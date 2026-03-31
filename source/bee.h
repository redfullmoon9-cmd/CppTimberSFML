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
	void SetActive(bool act);
	bool GetActive() const { return isActive; }
private: 
	float m_degree{ 0 }; 

protected: 
	bool isActive = false;
};

#endif //__BEE_H__