#ifndef __TEXT_MANAGER_H__
#define __TEXT_MANAGER_H__
#include "header.h"
class TextManager {
public: 
	TextManager(const std::string& fileName); 
	~TextManager(); 
private: 
	sf::Font m_font; 
	sf::Text m_messageText;
	sf::Text m_scoreText; 
};

#endif//__TEXT_MANAGER_H__ 