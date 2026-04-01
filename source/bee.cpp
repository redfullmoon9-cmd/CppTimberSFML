#include "bee.h"

Bee::Bee(const std::string& fileName, int posX, int posY, float speed)
	:GameObject(fileName, posX, posY)
{
	setSpeed(speed); 
	isActive = false; 
	//std::cout << "in bee contructor" << std::endl; 
}

Bee::Bee(const sf::Texture& texture, int posX, int posY, float speed) 
	:GameObject(texture, posX, posY, speed)
{
}

Bee::~Bee()
{
}

void Bee::setDegree(int degree)
{
	m_degree = degree; 
	getSprite().setRotation((float)m_degree); 

}

void Bee::setActive(bool act)
{
	isActive = act; 
}


// 클로드 제안 코드 -- 코드의 통일성을 유지하기 위해서 timberMain에서 
// bee 좌표 이동을 이곳으로 옮김. 
void Bee::update(float dt)
{
	if (!isActive) return; 
	float newX = getPostiotionX() - (getSpeed() *dt);
	setPosition(newX, getPostiotionY()); 

	if (newX < 100) {
		isActive = false; 
	}

}


