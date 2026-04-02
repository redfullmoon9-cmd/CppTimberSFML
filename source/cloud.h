#ifndef __CLOUD_H__
#define __CLOUD_H__

#include "header.h"
#include "gameobject.h"
class Cloud :public GameObject {
public: 
	Cloud(const std::string& fileName, int posX, int posY, float speed, uint32_t height);
	Cloud(const sf::Texture& texture, int posX, int posY, float speed, uint32_t height); 
	
	~Cloud();
	void update(float dt); 
	bool getActive() const { return isActive; }
	void setActive(bool act); 
private: 
	bool isActive = false; 
	uint32_t m_cloudHeightMin{ 0 }; 
	uint32_t m_cloudHeightMax{ 0 }; 

};


#endif //__CLOUD_H__