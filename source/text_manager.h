#ifndef __TEXT_MANAGER_H__
#define __TEXT_MANAGER_H__

#include "header.h"

class TextManager {
public: 
	TextManager(const std::string& fileName, const std::string& message, uint32_t characterSize,  bool centered=false);
	~TextManager(); 
	sf::Font getFont() const { return m_font;  }
	void setFont(sf::Font font); 

	sf::Text& getText(){ return m_text; }
	const sf::Text& getText() const{ return m_text; }

	TextManager(const TextManager&) = delete; 
	TextManager& operator=(const TextManager&) = delete; 
	TextManager(const TextManager&& other) noexcept; 

	void setPosition(float width, float height); //
	void setString(const std::string& message); 
	//새로운 문자열이 주어지면 중앙정렬을 한다. 
	void setStringCentered(const std::string& message, float x, float y); 
private: 
	sf::Font m_font; 
	sf::Text m_text;
	void centerOrigin(); //

};

#endif//__TEXT_MANAGER_H__ 