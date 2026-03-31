#include "bee.h"

Bee::Bee(const std::string& fileName, int posX, int posY, float speed, float degree)
	:GameObject(fileName, posX, posY, speed), m_degree(degree)
{

}

Bee::~Bee()
{
}

void Bee::SetDegree(int degree)
{
	m_degree = degree; 

}
