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
	void Update(float dt); // 코드 통일성 문제로 .. 
private: 
	float m_degree{ 0 }; 
	bool isActive = false;

protected: 
};

#endif //__BEE_H__