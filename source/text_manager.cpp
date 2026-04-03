#include "text_manager.h"

TextManager::TextManager(const std::string& fileName)
{
	m_font.loadFromFile(fileName); 
	m_text.setFont(m_font); 
	m_text.setString("Press enter to start"); 
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
