#ifndef __TEXT_MANAGER_H__
#define __TEXT_MANAGER_H__
#include "header.h"
class TextManager {
public: 
	TextManager(const std::string& fileName, const std::string& message);
	~TextManager(); 
	sf::Font getFont() const { return m_font;  }
	void setFont(sf::Font font); 

	sf::Text getText() const { return m_text; }

	TextManager(const TextManager&) = delete; 
	TextManager& operator=(const TextManager&) = delete; 
	TextManager(const TextManager&& other) noexcept; 

	void setTextRect(); 
	void setPosition(float width, float height, uint32_t mode);
	void setString(const std::string& mString); 
private: 
	sf::Font m_font; 
	sf::Text m_text;
	sf::FloatRect m_textRect; 
	//std::string m_string; 
};

#endif//__TEXT_MANAGER_H__ 