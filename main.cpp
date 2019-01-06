#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Display.h"
#include <vector>
#include "EnemyCars.h"
#include "MyCar.h"
#include "IOSubject.h"


IOSubject inputOutputSubject;
MyCarComponent myCarComponent(inputOutputSubject);
DisplayComponent display;
EnemyCarsComponent enemyCarsComponent;
sf::Music music;
sf::RenderWindow window(sf::VideoMode(COLS, ROWS), "My window");

bool isCollision(const vector<sf::Sprite>& carsArg , sf::Sprite& myCarArg)
{

	return false;
}


int main()
{
	
	sf::Clock tempClock;


	sf::Time elpTime = tempClock.getElapsedTime();
	std::cout<<"elpTime = "<<elpTime.asMicroseconds()<<std::endl;

	window.setVerticalSyncEnabled(true);

	if(!music.openFromFile("music.ogg"))
	{
		std::cout<<"Can't load the music !"<<std::endl;
	}

	music.play();


	while(window.isOpen())
	{
				
		sf::Clock clock;
		
		inputOutputSubject.update(window);
		
		//if(isCollision(enemyCarsComponent.getEnemyCars() , my))

		window.clear();

		display.update();		
		enemyCarsComponent.update(window);
		myCarComponent.update(window);

		window.draw(display.GetArrayOfVerticies() , display.GetNrOfVerticies() , sf::Lines);				
		window.display();
		sf::Time timeElapsed = clock.getElapsedTime();		
		//std::cout<<"time elapsed mu = "<<timeElapsed.asMicroseconds()<<std::endl;
		sf::sleep(sf::milliseconds(20 - timeElapsed.asMilliseconds()));		
		
	}

	return 0;
}