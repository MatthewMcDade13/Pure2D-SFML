#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include <unordered_map>
#include <iterator>
#include <memory>
#include <functional>
#include <utility>

namespace pure
{
	template<typename T>
	class PUREENGINE_API ResourceManager
	{
	public:
		ResourceManager() { };
		~ResourceManager() { };

		ResourceManager(const ResourceManager<T>& rm) = delete;
		ResourceManager& operator=(const ResourceManager<T>& rm) = delete;

		T* get(const std::string& filePath)
		{
			using namespace std; using namespace sf;

			auto it = m_resources.find(filePath);

			if (it != m_resources.end())
				return *(it->second);

			auto loadFile = fromFile<T>(filePath);
			unique_ptr<T> resource(new T());

			if (!loadFile(*resource))
			{
				return nullptr;
			}

			// Store refrence to resource before we move the pointer
			// into the map so we can return it
			T& resourceRef = *resource;

			m_resources.insert(pair<string, unique_ptr<T>>(filePath, std::move(resource)));

			return resourceRef;
		}

	private:
		std::unordered_map<std::string, std::unique_ptr<T>> m_resources;

		template <class R>
		std::function<bool(R&)> fromFile(const std::string& filePath)
		{
			return std::function<bool(R&)>(
				[&](R& resource) {
				bool result = resource.loadFromFile(filePath);
				return result;
			});
		}
	};
}
