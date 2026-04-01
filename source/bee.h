#ifndef __BEE_H__
#define __BEE_H__
#include "header.h"
#include "gameobject.h"
class Bee :public GameObject {
public: 
	Bee(const std::string& fileName, int posX, int posY, float speed);
	Bee(const sf::Texture& texture, int posX, int posY, float speed); 
	~Bee(); 
	float setDegree() const { m_degree; }
	void setDegree( int degree); 
	void setActive(bool act);
	bool getActive() const { return isActive; }
	void update(float dt); // 코드 통일성 문제로 .. 
private: 
	float m_degree{ 0 }; 
	bool isActive = false;

protected: 
};

#endif //__BEE_H__