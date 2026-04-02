//#pragma once
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include "header.h"


class GameObject {
public: 
	GameObject(const std::string& fileName, int posX, int posY);
	GameObject(const sf::Texture& texture, int posX, int posY, float speed); 
	//이동 생성자-Texture 문제발생. 포인터 깨지는 문제. 
	GameObject(GameObject&& other) noexcept; 
	//복사 생성자 포인트 무효화 문제 해결을 위해서 복사이동 둘다 있어야. . 
	GameObject(const GameObject& other) ; 

	~GameObject();
	void setPosition(float x, float y); 
	float getPostiotionX() const { return m_positionX; }
	float getPostiotionY() const { return m_positionY; }
	//복사본 반환 문제 레퍼런스가 아닌 경우 매번 새로운 복사본이 생성되어서 반환 따라서 변경을 해도 변경의 반영이 않된다. 
	sf::Sprite& getSprite() { return m_sprite;  } 
	void setSpeed(float speed); 
	float getSpeed() const { return m_speed;  }
	sf::Texture& getTexture() { return m_texture; }
protected:
	sf::Sprite m_sprite; 

private:
	sf::Texture m_texture; 
	float m_positionX{ 0 };
	float m_positionY{ 0 }; 
	float m_speed{ 0 }; 
	
};

#endif //__GAMEOBJECT_H__
