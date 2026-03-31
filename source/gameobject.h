//#pragma once
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
#include "header.h"

class GameObject {
public: 
	GameObject(const std::string& fileName, int posX, int posY, float speed);
	~GameObject();
	void SetPosition(int x, int y); 
	int GetPostiotionX() const { return m_positionX; }
	int GetPostiotionY() const { return m_positionY; }
	sf::Sprite GetSprite() { return m_sprite;  }
	void setActive(bool act); 
	bool getActive() const { return m_active;  }
	void setSpeed(float speed); 
	float getSpeed() const { return m_speed;  }
private:
	sf::Texture m_texture; 
	sf::Sprite m_sprite; 
	bool m_active = false; 
	int m_positionX{ 0 };
	int m_positionY{ 0 }; 
	float m_speed{ 0 }; 
	std::vector<int> m_vecPosition; 
};

#endif //__GAMEOBJECT_H__
