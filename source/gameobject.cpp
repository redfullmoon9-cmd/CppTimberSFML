#include "gameobject.h"

GameObject::GameObject(const std::string& fileName, int posX, int posY)
	:m_positionX((float)posX), m_positionY((float)posY)
{
	std::cout << "game object " << fileName.c_str() << std::endl; 
	m_texture.loadFromFile(fileName); 
	m_sprite.setTexture(m_texture); 

	//m_vecPosition = { m_positionX,m_positionY }; 
	m_sprite.setPosition(m_positionX, m_positionY); 

}

GameObject::GameObject(const sf::Texture& texture, int posX, int posY, float speed) 
	: m_positionX((float) posX), m_positionY((float) posY), m_speed(speed)
{
	m_texture = texture; 
	m_sprite.setTexture(m_texture); 
	m_sprite.setPosition(m_positionX, m_positionY); 
}

//cloud와 vector를 함께 사용했을때 메모리 복사가 일어나 텍스쳐 주소를 못가져오는 문제
// 복사 생성자를 만들어 텍스쳐를 복사하고 다시 스프라이트에 연결한다. 
GameObject::GameObject(GameObject &&other) noexcept 
	: m_texture(std::move(other.m_texture)), m_sprite(other.m_sprite), 
	m_positionX(other.m_positionX), m_positionY(other.m_positionY), m_speed(other.m_speed)
{
	m_sprite.setTexture(m_texture); 
}

GameObject::GameObject(const GameObject &other) 
: m_texture(std::move(other.m_texture)), m_sprite(other.m_sprite), 
m_positionX(other.m_positionX), m_positionY(other.m_positionY), m_speed(other.m_speed)
{
	m_sprite.setTexture(m_texture); 
}


GameObject::~GameObject()
{
}

void GameObject::setPosition(float x, float y)
{
	m_positionX = x; 
	m_positionY = y; 
	m_sprite.setPosition(m_positionX, m_positionY); 
}


void GameObject::setSpeed(float speed)
{
	m_speed = speed; 

}
