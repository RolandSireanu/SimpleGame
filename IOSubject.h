#ifndef IOOBSERVER_H
#define IOOBSERVER_H

#include "SFML/Graphics.hpp"
#include <vector>

class IObserver;


class IOSubject
{

	public:


		void attach(IObserver* obs)
		{
			observers.push_back(obs);
		}


		void update(sf::RenderWindow& window);		

	private:

		std::vector<IObserver*> observers;

};















#endif