#include "gameobject.h"

GameObject::GameObject(const std::string& fileName, int posX, int posY, float speed)
	:m_positionX(posX), m_positionY(posY), m_speed(speed)

{
	m_texture.loadFromFile(fileName); 
	m_sprite.setTexture(m_texture); 

	m_vecPosition = { m_positionX,m_positionY }; 
	m_sprite.setPosition((float)m_positionX, (float)m_positionY); 

}

GameObject::~GameObject()
{
}

void GameObject::SetPosition(int x, int y)
{
	m_positionX = x; 
	m_positionY = y; 
}


void GameObject::setSpeed(float speed)
{
	m_speed = speed; 
}
