// #pragma once 

#include <iostream>
#include <sstream>
#include "header.h"
#include "gameobject.h"
#include "bee.h"


namespace userCode{

	void updateBranches(int seed);
	//const int NUM_BRANCHES = 6;  //heaer.hpp 
	sf::Sprite branches[NUM_BRANCHES];

	enum class side { LEFT, RIGHT, NONE };
	side branchPositions[NUM_BRANCHES];


	int userMain() {
		//Vector2f test;
		//RectangleShape shape; 

		sf::VideoMode vm(SCREEN_WIDTH, SCREEN_HEIGHT);
		sf::RenderWindow r_window(vm, "Timber", sf::Style::Fullscreen);

		//background
		GameObject backGround= GameObject(BG_IMG, 0, 0, 0.0f);
		//tree
		GameObject textureTree = GameObject(TREE_IMG, 810, 0, 0.0f);
	

		//Bee 
		Bee bee = Bee(BEE_IMG, 0, 800, 0.0f, 45); 
		/*sf::Texture textureBee;
		textureBee.loadFromFile(BEE_IMG);
		sf::Sprite spriteBee;
		spriteBee.setTexture(textureBee);
		spriteBee.setPosition(0, 800);
		spriteBee.setRotation(45);*/
		

		//bool beeActive = false;
		//float beeSpeed = 0.0f;

		//cloud
		sf::Texture textureCloud;
		textureCloud.loadFromFile(CLOUD_IMG);

		sf::Sprite spriteCloud1;
		sf::Sprite spriteCloud2;
		sf::Sprite spriteCloud3;

		spriteCloud1.setTexture(textureCloud);
		spriteCloud2.setTexture(textureCloud);
		spriteCloud3.setTexture(textureCloud);

		spriteCloud1.setPosition(0, 0);
		spriteCloud2.setPosition(0, 250);
		spriteCloud3.setPosition(0, 500);

		bool cloud1Active = false;
		bool cloud2Active = false;
		bool cloud3Active = false;

		float cloud1Speed = 0.0f;
		float cloud2Speed = 0.0f;
		float cloud3Speed = 0.0f;

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

		/* draw tect*/
		int score = 0;
		sf::Text messageText;
		sf::Text scoreText;
		sf::Font font;
		font.loadFromFile(FONT_KOMIKAP);
		messageText.setFont(font);
		scoreText.setFont(font);

		messageText.setString("Press enter to start");
		scoreText.setString("Score=0");

		messageText.setCharacterSize(75);
		scoreText.setCharacterSize(100);

		messageText.setFillColor(sf::Color::White);
		scoreText.setFillColor(sf::Color::White);

		sf::FloatRect textRect = messageText.getGlobalBounds();
		messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		messageText.setPosition(SCREEN_WIDTH / 2.0F, SCREEN_HEIGHT / 2.0f);
		scoreText.setPosition(20, 20);

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

		sf::SoundBuffer chopBuffer; 
		chopBuffer.loadFromFile(CHOP_SOUND); 
		sf::Sound chop; 
		chop.setBuffer(chopBuffer); 

		sf::SoundBuffer deathBuffer; 
		deathBuffer.loadFromFile(DEATH_SOUND); 
		sf::Sound death; 
		death.setBuffer(deathBuffer); 

		sf::SoundBuffer ootBuffer; 
		ootBuffer.loadFromFile(OOT_SOUND);
		sf::Sound OutOfTime; 
		OutOfTime.setBuffer(ootBuffer); 



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
				}

				//set up the bee 
				if (!bee.GetActive()) {
					//std::cout << " bee if active " << bee.getActive() << std::endl; 
					srand((int)time(0));
					bee.setSpeed(static_cast<float>((rand() % 200) + 200));

					std::cout << " bee speed " << bee.getSpeed() << std::endl; 
					srand((int)time(0) * 10);
					float height = static_cast<float>((rand() % 500) + 500);
					bee.SetPosition(2000, height); 
					bee.SetActive(true);

				}
				else {
					std::cout << " bee else active " << bee.GetActive() << std::endl; 
					bee.GetSprite().setPosition(bee.GetSprite().getPosition().x - (bee.getSpeed() * dt.asSeconds()), 
						bee.GetSprite().getPosition().y);
					if (bee.GetSprite().getPosition().x < -100) {
						bee.SetActive(false);
					}
				}
				/*
				if (!beeActive) {
					srand((int)time(0));
					beeSpeed = static_cast<float>((rand() % 200) + 200);

					srand((int)time(0) * 10);
					float height = static_cast<float>((rand() % 500) + 500);
					spriteBee.setPosition(2000, height);
					beeActive = true;

				}
				else {
					spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
						spriteBee.getPosition().y);
					if (spriteBee.getPosition().x < -100) {
						beeActive = false;
					}
				}*/

				//cloud1Active
				if (!cloud1Active) {
					srand((int)time(0) * 10);
					cloud1Speed = static_cast<float>((rand() % 200));

					srand((int)time(0) * 10);
					float height = static_cast<float>((rand() % 150));
					spriteCloud1.setPosition(-200, height);
					cloud1Active = true;
				}
				else {
					spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()),
						spriteCloud1.getPosition().y);

					if (spriteCloud1.getPosition().x > 1920) cloud1Active = false;
				}

				//cloud2Active
				if (!cloud2Active) {
					srand((int)time(0) * 20);
					cloud2Speed = static_cast<float> ((rand() % 200));

					srand((int)time(0) * 20);
					float height = static_cast<float> ((rand() % 300) - 150);
					spriteCloud2.setPosition(-200, height);
					cloud2Active = true;
				}
				else {
					spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()),
						spriteCloud2.getPosition().y);

					if (spriteCloud2.getPosition().x > 1920) cloud2Active = false;
				}


				//cloud3Active
				if (!cloud3Active) {
					srand((int)time(0) * 30);
					cloud3Speed = static_cast<float>((rand() % 200));

					srand((int)time(0) * 30);
					float height = static_cast<float>((rand() % 450) - 150);
					spriteCloud3.setPosition(-200, height);
					cloud3Active = true;
				}
				else {
					spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()),
						spriteCloud3.getPosition().y);

					if (spriteCloud3.getPosition().x > 1920) cloud3Active = false;
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

				}
			}

			/* draw screen */
			r_window.clear();
			r_window.draw(backGround.GetSprite());

			r_window.draw(spriteCloud1);
			r_window.draw(spriteCloud2);
			r_window.draw(spriteCloud3);

			for (int i = 0; i < NUM_BRANCHES; i++) {
				r_window.draw(branches[i]);
			}

			r_window.draw(textureTree.GetSprite());

			r_window.draw(spritePlayer);
			r_window.draw(spriteAxe);
			r_window.draw(spriteLog);
			r_window.draw(spriteRIP);


			//draw spriteBee 
			//r_window.draw(spriteBee);
			r_window.draw(bee.GetSprite());
							 
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


