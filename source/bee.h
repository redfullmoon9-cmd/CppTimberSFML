#ifndef __BEE_H__
#define __BEE_H__
#include "header.h"
#include "gameobject.h"
class Bee :public GameObject {
public: 
	Bee(const std::string& fileName, int posX, int posY, float speed, float degree);
	~Bee(); 
	float GetDegree() const { m_degree; }
	void SetDegree( int degree); 
private: 
	float m_degree{ 0 }; 
};

#endif //__BEE_H__