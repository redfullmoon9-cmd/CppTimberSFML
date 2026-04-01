//#pragma once
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "header.h"

class GameObject {
public: 
	GameObject(const std::string& fileName, int posX, int posY, float speed);
	~GameObject();
	void SetPosition(float x, float y); 
	float GetPostiotionX() const { return m_positionX; }
	float GetPostiotionY() const { return m_positionY; }
	sf::Sprite& GetSprite() { return m_sprite;  } //복사본 반환 문제 
	void setSpeed(float speed); 
	float getSpeed() const { return m_speed;  }

protected:
	sf::Sprite m_sprite; 

private:
	sf::Texture m_texture; 
	float m_positionX{ 0 };
	float m_positionY{ 0 }; 
	float m_speed{ 0 }; 
	//std::vector<int> m_vecPosition; 
	//bool m_active = false; 
};

#endif //__GAMEOBJECT_H__
