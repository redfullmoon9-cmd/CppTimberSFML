#include "text_manager.h"

TextManager::TextManager(const std::string& fileName, const std::string& message)
{
	m_font.loadFromFile(fileName); 
	m_text.setFont(m_font); 
	m_text.setString(message);
	m_text.setCharacterSize(75); 
	m_text.setFillColor(sf::Color::White); 

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

void TextManager::setTextRect()
{
	m_textRect = m_text.getGlobalBounds(); 
}

void TextManager::setPosition(float width, float height, uint32_t mode)
{
	if (mode == 1) {
		m_text.setOrigin(m_textRect.left + m_textRect.width / 2.0f, m_textRect.top + m_textRect.height / 2.0f); 

	}
	else {
		m_text.setPosition(width,  height);

	}
}

void TextManager::setString(const std::string& mString)
{
	m_text.setString(mString); 
}
