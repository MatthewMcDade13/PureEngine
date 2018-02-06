#include "stdafx.h"
#include "Entity.h"

using namespace pure;

Entity::Entity(): m_velocity({0.f,0.f})
{
}


Entity::~Entity()
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	m_velocity = velocity;
}

void Entity::setVelocity(float velX, float velY)
{
	m_velocity = sf::Vector2f(velX, velY);
}

void pure::Entity::addVelocity(sf::Vector2f velocity)
{
	m_velocity += velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	return m_velocity;
}

