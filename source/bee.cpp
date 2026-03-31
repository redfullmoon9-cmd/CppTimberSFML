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

}

void Bee::SetActive(bool act)
{
	isActive = act; 
}


