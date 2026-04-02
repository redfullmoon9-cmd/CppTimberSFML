#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "header.h"

class SoundManager{
public :
    SoundManager(std::string& fileName); 
    ~SoundManager(); 
    void play();
    sf::Sound& getSound(){return m_sound; } 
    
private:
    sf::Sound m_sound;
    sf::SoundBuffer m_soundBuffer;  
}; 


#endif //__SOUND_MANAGER_H__

