// #pragma once
#ifndef __HEADER_H__
#define __HEADER_H__

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//window와 linux 동시에 사용하도록 
#ifdef _WIN32
    #define RESOURCE_PATH "D://cNcpp//CppTimberSFML//resources//"
#else  
    #define RESOURCE_PATH "/home/hotphotatos/cNcppGameDev/CppTimberSFML/resources/"
#endif

constexpr auto BG_IMG = RESOURCE_PATH "graphics/background.png";
constexpr auto TREE_IMG = RESOURCE_PATH "graphics/tree.png";
constexpr auto BEE_IMG = RESOURCE_PATH "graphics/bee.png";
constexpr auto CLOUD_IMG = RESOURCE_PATH "graphics/cloud.png";
constexpr auto BRANCH_IMG = RESOURCE_PATH "graphics/branch.png"; 
constexpr auto PLAYER_IMG = RESOURCE_PATH "graphics/player.png";
constexpr auto RIP_IMG = RESOURCE_PATH "graphics/rip.png";
constexpr auto AXE_IMG = RESOURCE_PATH "graphics/axe.png";
constexpr auto LOG_IMG = RESOURCE_PATH "graphics/log.png";

constexpr auto CHOP_SOUND= RESOURCE_PATH "sound/chop.wav";
constexpr auto DEATH_SOUND= RESOURCE_PATH "sound/death.wav";
constexpr auto OOT_SOUND= RESOURCE_PATH "sound/out_of_time.wav";

constexpr auto FONT_KOMIKAP = RESOURCE_PATH "fonts//KOMIKAP_.ttf"; 

constexpr auto SCREEN_WIDTH = 1920; 
constexpr auto SCREEN_HEIGHT = 1080; 

constexpr auto NUM_BRANCHES = 6; 

constexpr auto AXE_POSITION_LEFT = 700;
constexpr auto AXE_POSITION_RIGHT = 1075;


#endif //__HEADER_H__