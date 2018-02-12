#pragma once

#include <string>
#include <unordered_map>
#include <iterator>
#include <memory>
#include <utility>
#include <assert.h>

namespace pure
{
	template<typename T>
	class ResourceManager
	{

	public:
		ResourceManager() { };
		~ResourceManager() { };

		T* get(const std::string& filePath)
		{
			using namespace std;
			{
				T* existingResource = findResource(filePath);

				if (existingResource) return existingResource;
			}

			return createResource(filePath);
		}

		// Used to handle loading shaders or for calling other resource loadFromFileOverloads that take
		// two parameters.
		template <typename Param>
		T* get(const std::string& filePath, const Param& secondParam)
		{
			using namespace std; using namespace sf;

			{
				T* existingResource = findResource(filePath);

				if (existingResource) return existingResource;
			}

			return createResource(filePath, secondParam);
		}

		// Load a resource into memory to be used later
		bool load(const std::string& filePath)
		{
			using namespace std; using namespace sf;

			// Resource has already been loaded, do nothing and return false
			if (findResource(filePath)) return false;

			return createResource(filePath) != nullptr;
		}

		// Load a resource or shader into memory to be used later
		template <typename Param>
		bool load(const std::string& filePath, const Param& secondParam)
		{
			using namespace std; using namespace sf;

			// Resource has already been loaded, do nothing and return false
			if (findResource(filePath)) return false;

			return createResource(filePath, secondParam) != nullptr;
		}

	protected:
		std::unordered_map<std::string, std::unique_ptr<T>> m_resources;

	private:
		T* insertResource(const std::string& filePath, std::unique_ptr<T> resource)
		{
			using namespace std; using namespace sf;
			// Store refrence to resource before we move the pointer
			// into the map so we can return it
			T* resourceRef = resource.get();

			auto inserted = m_resources.insert(pair<string, unique_ptr<T>>(filePath, move(resource)));

			if (!inserted.second)
				return nullptr;

			return resourceRef;
		}

		T* findResource(const std::string& filePath)
		{
			using namespace std; using namespace sf;

			auto it = m_resources.find(filePath);

			if (it != m_resources.end())
				return it->second.get();

			return nullptr;
		}

		T* createResource(const std::string& filePath)
		{
			using namespace std; using namespace sf;

			unique_ptr<T> resource = make_unique<T>();

			if (!resource->loadFromFile(filePath))
				return nullptr;

			return insertResource(filePath, move(resource));
		}

		template <typename Param>
		T* createResource(const std::string& filePath, const Param& secondParam)
		{
			using namespace std; using namespace sf;

			unique_ptr<T> resource = make_unique<T>();

			if (!resource->loadFromFile(filePath, secondParam))
				return nullptr;

			return insertResource(filePath, move(resource));
		}
	};
}
