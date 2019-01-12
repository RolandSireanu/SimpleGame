#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>
#include <iostream>
#include "Display.h"
#include <vector>
#include "EnemyCars.h"
#include "MyCar.h"
#include "IOSubject.h"
#include <stack>
#include "UserDefConv.h"


namespace 
{

	//Input output and my car observer pattern 
	IOSubject inputOutputSubject;	
	MyCarComponent myCarComponent(inputOutputSubject);

	//Background of game 
	DisplayComponent display;

	//Enemy cars component 
	EnemyCarsComponent enemyCarsComponent;

	//Audio part of game 
	sf::Music music;

	//Main window of the game 
	sf::RenderWindow window(sf::VideoMode(COLS, ROWS), "My window");

};

bool isCollision(const vector<sf::Sprite>& carsArg , sf::Sprite& myCarArg)
{

	return false;
}

int main()
{
	
	sf::Clock tempClock;
	TestClass tc;

	std::cout<<int(tc)<<std::endl;

	sf::Time elpTime = tempClock.getElapsedTime();
	std::cout<<"elpTime = "<<elpTime.asMicroseconds()<<std::endl;

	window.setVerticalSyncEnabled(true);

	if(!music.openFromFile("music.ogg"))
	{
		std::cout<<"Can't load the music !"<<std::endl;
	}

	//Let it play !
	music.play();


	while(window.isOpen())
	{
		//Create timer
		sf::Clock clock;
		
		window.clear();

		//Update components 
		inputOutputSubject.update(window);
		display.update();		
		enemyCarsComponent.update(window);
		myCarComponent.update(window);

		//Draw the background 
		window.draw(display.GetArrayOfVerticies() , display.GetNrOfVerticies() , sf::Lines);	

		//Display the window 			
		window.display();
		sf::Time timeElapsed = clock.getElapsedTime();		



		#ifdef DEBUG
		std::cout<<"time elapsed mu = "<<timeElapsed.asMicroseconds()<<std::endl;
		#endif


		sf::sleep(sf::milliseconds(20 - timeElapsed.asMilliseconds()));		
		
	}

	return 0;
}
