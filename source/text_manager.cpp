#include "text_manager.h"

TextManager::TextManager(const std::string& fileName)
{
	m_font.loadFromFile(fileName); 
	m_messageText.setFont(m_font); 
	m_messageText.setString("Press enter to start"); 
	m_messageText.setCharacterSize(75); 
	m_messageText.setFillColor(sf::Color::White); 

	m_scoreText.setFont(m_font); 
	m_scoreText.setString("Score=0"); 
	m_scoreText.setCharacterSize(100); 
	m_scoreText.setFillColor(sf::Color::White); 
	)



}

TextManager::~TextManager()
{
}
