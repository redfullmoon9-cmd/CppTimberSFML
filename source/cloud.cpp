#include "cloud.h"

Cloud::Cloud(const std::string& fileName, int posX, int posY, float speed, uint32_t height)
	: GameObject(fileName, posX, posY), m_cloudHeightMax(height)
{
	//std::cout << "in cloud constructor" << std::endl; 
	setSpeed(speed); 
	m_cloudHeightMin = m_cloudHeightMax - 150;

}

Cloud::Cloud(const sf::Texture& texture, int posX, int posY, float speed, uint32_t height)
	: GameObject(texture, posX, posY, speed), m_cloudHeightMax(height)
{
	//getTexture()
	//std::cout << "in cloud texture constructor" << std::endl; 
	m_cloudHeightMin = m_cloudHeightMax - 150; 

}

Cloud::~Cloud()
{
}

void Cloud::update(float dt) {
	srand((int)time(0) * 20);
	if (!isActive) {
		setSpeed( static_cast<float>((rand() % 200)+50));
		float height = static_cast<float>(rand() % (m_cloudHeightMax ));
		setPosition(-200, height); 
		isActive = true; 
		//std::cout << " update : posX " << getPostiotionX() << " posY" << getPostiotionY() << std::endl; 

	}
	else {
		float newX = getPostiotionX() + (getSpeed() * dt); 
		setPosition(newX, getPostiotionY()); 
		if (newX > 1920) {
			isActive = false;
		}
	}

}
