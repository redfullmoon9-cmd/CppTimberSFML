#include "sound_manager.h"

SoundManager::SoundManager(const std::string& fileName)
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

SoundManager::SoundManager(SoundManager&& other) noexcept
{
    m_soundBuffer = std::move(other.m_soundBuffer); 
    m_sound.setBuffer(m_soundBuffer); 
}
