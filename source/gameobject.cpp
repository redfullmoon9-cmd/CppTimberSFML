#include "gameobject.h"

GameObject::GameObject(const std::string& fileName, int posX, int posY, float speed)
	:m_positionX((float)posX), m_positionY((float)posY), m_speed(speed)

{
	m_texture.loadFromFile(fileName); 
	m_sprite.setTexture(m_texture); 

	//m_vecPosition = { m_positionX,m_positionY }; 
	m_sprite.setPosition(m_positionX, m_positionY); 

}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(float x, float y)
{
	m_positionX = x; 
	m_positionY = y; 
	m_sprite.setPosition(m_positionX, m_positionY); 
}


void GameObject::setSpeed(float speed)
{
	m_speed = speed; 

}
