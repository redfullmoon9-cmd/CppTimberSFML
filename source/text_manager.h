#ifndef __TEXT_MANAGER_H__
#define __TEXT_MANAGER_H__
#include "header.h"
class TextManager {
public: 
	TextManager(const std::string& fileName); 
	~TextManager(); 
	sf::Font getFont() const { return m_font;  }
	void setFont(sf::Font font); 

	sf::Text getText() const { return m_text; }

	TextManager(const TextManager&) = delete; 
	TextManager& operator=(const TextManager&) = delete; 
	TextManager(const TextManager&& other) noexcept; 

private: 
	sf::Font m_font; 
	sf::Text m_text;
	//sf::FloatRect m_textRect; 
};

#endif//__TEXT_MANAGER_H__ 