#include "text_manager.h"

TextManager::TextManager(const std::string& fileName, const std::string& message, 
	uint32_t characterSize, bool centered)
{
	m_font.loadFromFile(fileName); 
	m_text.setFont(m_font); 
	m_text.setString(message);
	m_text.setCharacterSize(characterSize);
	m_text.setFillColor(sf::Color::White); 
	if (centered) {
		centerOrigin(); 
	}

}

TextManager::~TextManager()
{
}

void TextManager::setFont(sf::Font font)
{
	m_text.setFont(font); 
}

TextManager::TextManager(const TextManager&& other) noexcept
{
	m_font = std::move(other.m_font); 
	m_text.setFont(m_font); 
}



void TextManager::setPosition(float width, float height)
{
	m_text.setPosition(width,  height);
	
}

void TextManager::setString(const std::string& message)
{
	m_text.setString(message);
}

void TextManager::setStringCentered(const std::string& message, float x, float y)
{
	m_text.setString(message); 
	centerOrigin(); 
	m_text.setPosition(x, y); 

}

//문자열에 따라 중앙을 잡는 기능. 
void TextManager::centerOrigin()
{
	//문자열이 주어지면 크기를 측정
	sf::FloatRect rect = m_text.getGlobalBounds(); 
	// 측정된 크기에 따라서 중앙에 정렬. 
	m_text.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f); 
}
