#include "bee.h"

Bee::Bee(const std::string& fileName, int posX, int posY, float speed, float degree)
	:GameObject(fileName, posX, posY, speed), m_degree(degree)
{
	isActive = false; 
	std::cout << "in bee contructor" << std::endl; 
}

Bee::~Bee()
{
}

void Bee::SetDegree(int degree)
{
	m_degree = degree; 
	GetSprite().setRotation((float)m_degree); 

}

void Bee::SetActive(bool act)
{
	isActive = act; 
}

// 클로드 제안 코드 
void Bee::Update(float dt)
{
	if (!isActive) return; 
	float newX = GetPostiotionX() - (getSpeed() *dt);
	SetPosition(newX, GetPostiotionY()); 

	if (newX < 100) {
		isActive = false; 
	}

}


