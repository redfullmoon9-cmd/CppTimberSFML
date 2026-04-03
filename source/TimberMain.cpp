// #pragma once 

#include <iostream>
#include <sstream>
#include "header.h"
#include "gameobject.h"
#include "bee.h"
#include "cloud.h"
#include "sound_manager.h"
#include "text_manager.h"


namespace userCode{

	void updateBranches(int seed);
	//const int NUM_BRANCHES = 6;  //heaer.hpp 
	sf::Sprite branches[NUM_BRANCHES];

	enum class side { LEFT, RIGHT, NONE };
	side branchPositions[NUM_BRANCHES];


	int userMain() {
		sf::VideoMode vm(SCREEN_WIDTH, SCREEN_HEIGHT);
		sf::RenderWindow r_window(vm, "Timber", sf::Style::Fullscreen);

		//background
		GameObject backGround= GameObject(BG_IMG, 0, 0);
		//tree
		GameObject textureTree = GameObject(TREE_IMG, 810, 0);
	
		//Bee 
		Bee bee = Bee(BEE_IMG, 0, 800, 0.0f); 
	
		//cloud
		std::vector<Cloud> clouds; 
		clouds.reserve(3); 
		clouds.emplace_back(Cloud(CLOUD_IMG, 0, 0, 80.f, 150));
		clouds.emplace_back(Cloud(CLOUD_IMG, 0, 250, 100.0f, 300));
		clouds.emplace_back(Cloud(CLOUD_IMG, 0, 500, 50.f, 500));

		sf::Clock clock;

		//time bar 
		sf::RectangleShape timeBar;
		float timeBarStartWidth = 400.f;
		float timeBarHeight = 80.f;
		timeBar.setSize(sf::Vector2f(timeBarStartWidth, timeBarHeight));
		timeBar.setFillColor(sf::Color::Red);
		timeBar.setPosition((SCREEN_WIDTH / 2) - timeBarStartWidth / 2, 980);

		sf::Time gameTimeTotal;
		float timeRemaining = 6.0f;
		float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

		//track whether gamming is running 
		bool paused = true;

		/* draw text*/
		int score = 0;

		TextManager messageText(FONT_KOMIKAP, "Press enter to start");
		TextManager scoreText(FONT_KOMIKAP, "Score=0");

		messageText.setTextRect(); 
		messageText.setPosition(SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0f, 1); 
		scoreText.setPosition(20, 20, 0);

		/* prepare branches*/
		sf::Texture textureBranch;
		textureBranch.loadFromFile(BRANCH_IMG);

		for (int i = 0; i < NUM_BRANCHES; i++) {
			branches[i].setTexture(textureBranch);
			branches[i].setPosition(-2000, -2000);
			branches[i].setOrigin(220, 20);

		}

		//player 
		sf::Texture texturePlayer;
		texturePlayer.loadFromFile(PLAYER_IMG);
		sf::Sprite spritePlayer;
		spritePlayer.setTexture(texturePlayer);
		spritePlayer.setPosition(580, 720);

		side playerSide = side::LEFT; //player start left  


		//grave stone
		sf::Texture textureRIP;
		textureRIP.loadFromFile(RIP_IMG);
		sf::Sprite spriteRIP;
		spriteRIP.setTexture(textureRIP);
		spriteRIP.setPosition(600, 860);

		//AXE
		sf::Texture textureAxe;
		textureAxe.loadFromFile(AXE_IMG);
		sf::Sprite spriteAxe;
		spriteAxe.setTexture(textureAxe);
		spriteAxe.setPosition(700, 830);


		//Line the AXE up --> header 
		//const float AXE_POSITION_LEFT = 700;
		//const float AXE_POSITION_RIGHT = 1075;


		//flaying LOG 
		sf::Texture textureLog;
		textureLog.loadFromFile(LOG_IMG);
		sf::Sprite spriteLog;
		spriteLog.setTexture(textureLog);
		spriteLog.setPosition(810, 720);

		//
		bool logActive = false;
		float logSpeedX = 1000;
		float logSpeedY = -1500;

		bool acceptInput = false;

		// 현재 - 불필요한 임시 객체 생성 후 복사
		//SoundManager chop=SoundManager(CHOP_SOUND);
		 
		// 개선 - 직접 생성
		SoundManager chop(CHOP_SOUND); 
		SoundManager death(DEATH_SOUND); 
		SoundManager OutOfTime(OOT_SOUND); 

		/* main loop */
		while (r_window.isOpen()) {
			/*
			*******************
			handle the player input
			*******************
			*/
			sf::Event event;
			while (r_window.pollEvent(event)) {
				if (event.type == sf::Event::KeyReleased && !paused) {
					//listen released again 
					acceptInput = true;
					spriteAxe.setPosition(2000, spriteAxe.getPosition().y); //hide Axe
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				r_window.close();
			}

			/*start the game */
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				paused = false;

				score = 0;
				timeRemaining = 6;

				//처음 게임이 시작할때 가지의 위치는 모두 None로 설정. 
				for (int i = 0; i < NUM_BRANCHES; i++) {
					branchPositions[i] = side::NONE;
				}

				spriteRIP.setPosition(675, 2000);
				spritePlayer.setPosition(580, 720);
				acceptInput = true;
			}

			if (acceptInput) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					playerSide = side::RIGHT;
					score++;
					timeRemaining += (2.0f / score) + .15;
					spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
					spritePlayer.setPosition(1200, 700);
					updateBranches(score);

					//set the log flying to the left 
					spriteLog.setPosition(800, 720);
					logSpeedX = -5000;
					logActive = true;

					//play sound 
					chop.play(); 

					acceptInput = false;

				}

				//handle left cursor key
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					playerSide = side::LEFT;
					score++;
					timeRemaining += (2.0f / score) + .15;
					spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
					spritePlayer.setPosition(580, 720);
					updateBranches(score);

					spriteLog.setPosition(810, 720);
					logSpeedX = 5000;
					logActive = true;

					acceptInput = false;
				}
			}

			/* update screen */
			if (!paused) {
				sf::Time dt = clock.restart();

				timeRemaining -= dt.asSeconds();

				//타임바 크기 차이나는 부문 
				//게임이 시작되자마자 타임바의 너비가 화면 너비(1920)를 넘어가버립니다.
				// 시간이 1초 남았을 때가 되어서야 원래 의도했던 너비인 400이 됩니다.
				//timeBar.setSize(sf::Vector2f(timeBarStartWidth * timeRemaining, timeBarHeight));
				timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond* timeRemaining, timeBarHeight));

				if (timeRemaining <= 0.0f) {
					paused = true;
					messageText.setString("Out of Time");

					sf::FloatRect textRect = messageText.getLocalBounds();
					messageText.setOrigin(textRect.left + textRect.width / 2.0f,
						textRect.top + textRect.height / 2.0f);
					messageText.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
					OutOfTime.play(); 

				}

				//set up the bee 
				//벌이 않움직이는 문제는 복사본 전달 문제.  getSprite() 반환값은 복사본 
				//따라서 변경되지 않음. 레퍼런스 전달로 변경. 
				if (!bee.getActive()) {
					srand((int)time(0));
					bee.setSpeed(static_cast<float>((rand() % 200) + 200));

					srand((int)time(0) * 10);
					float height = static_cast<float>((rand() % 600) + 500);
					bee.setPosition(2000, height); 
					bee.setActive(true);

				}
				else { 
				//현재 이코드에서는 통일성 문제.. bee 클래스 내에서 업데이트로 통일성 유지 하는 것이 좋은 방향. 
					bee.update(dt.asSeconds()); 
				}
				
				//cloud1.update(dt.asSeconds()); 
				for (auto& cloud:clouds) {
					cloud.update(dt.asSeconds()); 
				}

				//update score text 
				std::stringstream ss;
				ss << "Score = " << score;
				scoreText.setString(ss.str());

				//update the branches 
				//실제 나무의 위치를 나무 위치값에 설정된 대로 setPosition으로 설정한다. 
				for (int i = 0; i < NUM_BRANCHES; i++) {
					float height = i * 150; //오타 i 대신 1로 .. 
					if (branchPositions[i] == side::LEFT) {
						branches[i].setPosition(610, height);
						branches[i].setOrigin(220, 40); //이부분이 왜 필요한가? 
						branches[i].setRotation(180);
					}
					else if (branchPositions[i] == side::RIGHT) {
						branches[i].setPosition(1330, height);
						branches[i].setOrigin(220, 40);
						branches[i].setRotation(0);
					}
					else { //hide
						branches[i].setPosition(3000, height);
					}
				}

				//handle flying log 1.14
				if (logActive) {
					spriteLog.setPosition(spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
						spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));
					if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) { //조건 오류 오타. 
						logActive = false;
						spriteLog.setPosition(810, 720);
					}
				}

				if (branchPositions[5] == playerSide) {
					paused = true; 
					acceptInput = false; 

					spriteRIP.setPosition(525, 760); 

					spritePlayer.setPosition(2000, 660); 
					messageText.setString("Squished!!"); 

					sf::FloatRect textRect = messageText.getLocalBounds();

					messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f); 
					messageText.setPosition(1920 / 2.0f, 1080 / 2.0f); 
					death.play(); 

				}
			}

			/* draw screen */
			r_window.clear();
			r_window.draw(backGround.getSprite());

			for (auto& cloud : clouds) {
				r_window.draw(cloud.getSprite()); 
			}

			for (int i = 0; i < NUM_BRANCHES; i++) {
				r_window.draw(branches[i]);
			}

			r_window.draw(textureTree.getSprite());

			r_window.draw(spritePlayer);
			r_window.draw(spriteAxe);
			r_window.draw(spriteLog);
			r_window.draw(spriteRIP);


			//draw spriteBee 
			//r_window.draw(spriteBee);
			r_window.draw(bee.getSprite());
							 
			//draw text 
			r_window.draw(scoreText);

			//draw time bar 
			r_window.draw(timeBar);

			if (paused) {
				r_window.draw(messageText);
			}

			r_window.display();
		}
		return 0;
	}

	void updateBranches(int seed) {
		//나무가지 위치 값이 0이 가장 위이고 5가 가장 아래(나무꾼 쪽) 것. 
		// 그래서 가장위인 0에서 가장 아래인 5번의 순서로 내려오게 됨. 
		// 여기서 업데이트가 일어나면 5는 4로 가고 0은 랜덤하게 새로운 나무 가지가 생성되고 방향이 결정. 
		for (int j = NUM_BRANCHES - 1; j > 0; j--) {
			branchPositions[j] = branchPositions[j - 1];
		}

		srand((int)time(0) + seed);
		int r = (rand() % 5);
		switch (r) {
		case 0:
			branchPositions[0] = side::LEFT;
			break;

		case 1:
			branchPositions[0] = side::RIGHT;
			break;

		default:
			branchPositions[0] = side::NONE;
			break;

		}

	}
}


