#include "IOSubject.h"
#include "IObserver.h"
#include <iostream>


void IOSubject::update(sf::RenderWindow& window)
{
	sf::Event event ;

	while(window.pollEvent(event))
	{		

		std::cout<<"IOSubject::update : Event "<<event.type<<"received !"<<std::endl;
		for(IObserver* obs : observers)
		{
			obs->addEventToQ(event);
		}
		
	}
}