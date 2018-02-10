#pragma once

#include "declspec.h"

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace pure
{
	class StateManager;

	class PUREENGINE_API State
	{
	public:
		State(StateManager* manager);
		virtual ~State();

		// Checks if current state is transparent,
		// If state is transparent, the state beneath it will get rendered as well.
		bool isTransparent() const;

		// Checks if current state is transcendant,
		// If state is transcendant, the state beneath it will get updated as well.
		bool isTranscendant() const;
		bool isActive() const;

		virtual void update(float deltaTime) = 0;

		virtual void draw(sf::RenderWindow& window) = 0;

		// Called when state is activated on state stack.
		virtual void activate() { }

		// Called when state is deactivated on state stack.
		virtual void deactivate() { }

		// Called when state is created from state manager.
		virtual void onCreate() { }

		// Called when state is destroyed from state manager.
		virtual void onDestroy() { }

		virtual void handleInput(const sf::Event& event) { }

	protected:
		bool m_bTransparent;
		bool m_bTranscendant;
		bool m_bActive;
		StateManager* m_stateManager;
	};
}
