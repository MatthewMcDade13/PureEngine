#pragma once

#ifdef PUREENGINE_EXPORTS
#define PUREENGINE_API __declspec(dllexport)
#else
#define PUREENGINE_API __declspec(dllimport)
#endif

#include <memory>
#include <unordered_map>
#include <functional>

namespace sf
{
	class Event;
	class Keyboard;
}


typedef std::function<void(float)> Action;

namespace pure
{
	class PUREENGINE_API Entity;

	class Player
	{
	public:
		Player();
		virtual ~Player();

		// Sets player entity to nullptr explicitly
		void removeEntity();

		void setEntity(std::unique_ptr<Entity>& entity);
		const Entity* getEntity() const;

		void bindKey(sf::Keyboard::Key key, Action actionBinding);
		void removeBinding(sf::Keyboard::Key key);

		// Handles single polled sfml events
		virtual void handleEvent(sf::Event& event) { }

		// Iterates over keybinds and calls bound function
		virtual void handleLiveInput(float deltaTime);

		virtual void setupPlayerInputs() { }

	protected:
		// Entity that the player is controlling
		std::unique_ptr<Entity> m_entity;
		std::unordered_map<sf::Keyboard::Key, Action> m_keybinds;
	};

}

