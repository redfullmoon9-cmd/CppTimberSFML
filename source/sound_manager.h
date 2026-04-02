#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "header.h"

class SoundManager{
public :
    SoundManager(const std::string& fileName); 
    ~SoundManager(); 
    void play();
    sf::Sound& getSound(){return m_sound; } 

    SoundManager(const SoundManager&) = delete; 
    SoundManager& operator=(const SoundManager&) = delete; 
    SoundManager(SoundManager&& other) noexcept; 
    
private:
    sf::SoundBuffer m_soundBuffer;//순서가 중요. buffer이 먼져 와야함. 
    sf::Sound m_sound;
}; 


#endif //__SOUND_MANAGER_H__

