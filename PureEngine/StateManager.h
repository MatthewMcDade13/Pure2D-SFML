#pragma once

#include "declspec.h"
#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>
#include <SFML/System/NonCopyable.hpp>

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace pure
{
	class State;

	class PUREENGINE_API StateManager : private sf::NonCopyable
	{
	public:
		StateManager(sf::RenderWindow& parentWindow);
		~StateManager();

		// Gets state at top of stack, null if empty
		State* getCurrentState();

		const sf::RenderWindow& getWindow() const;

		int getCurrentStateId() const;

		// Registers a state with a given factory function to be "lazy loaded" at runtime.
		// Requires a factory function to be called when lazy loaded, 
		// use this if state requires special setup in constructor.
		void registerState(int typeId, std::function<std::unique_ptr<State>(StateManager*)> stateFactory);

		// Registers a state to be "lazy loaded" at runtime.
		template <typename T>
		void registerState(int typeId)
		{
			auto factory = [](StateManager* manager) { return std::make_unique<T>(manager); };
			m_stateFactory.emplace(typeId, factory);
		}

		// Removes and destroys the state at the top of the stack,
		// then activate the new state at top of stack
		void popState();

		// Pushes new state to top of stack
		void pushState(int typeId);

		// Removes and destroys the given state, activates most recent state if state
		// destroyed was at top of stack
		bool removeState(int typeId);

		// Checks if state exists in stack
		bool hasState(int typeId);

		// Draws current state and all transparent states beneath it if current state is transparent
		void draw();

		// Updates current state and all transcendant states beneath it if current state is transcendant
		void update(float deltaTime);

		void handleInput(const sf::Event& event);

	private:
		sf::RenderWindow& m_window;
		std::vector<std::pair<int, std::unique_ptr<State>>> m_states;

		std::unordered_map<int, std::function<std::unique_ptr<State>(StateManager*)>> m_stateFactory;

		bool createState(int typeId);
	};
}


