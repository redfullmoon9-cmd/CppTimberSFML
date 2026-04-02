#include "sound_manager.h"

SoundManager::SoundManager(std::string& fileName)
{
    m_soundBuffer.loadFromFile(fileName); 
    m_sound.setBuffer(m_soundBuffer); 
}

SoundManager::~SoundManager()
{
}

void SoundManager::play()
{
    m_sound.play(); 
}
