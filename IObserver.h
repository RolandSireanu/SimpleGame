#ifndef IOBSERVER_H
#define IOBSERVER_H


#include <queue>
#include <iostream>
#include "IOSubject.h"


class IObserver
{

	public:

		IObserver(IOSubject& subject)
		{
			subject.attach(this);
		}

		virtual void addEventToQ(sf::Event ev) = 0;	

		virtual ~IObserver()
		{
			std::cout<<"~IObserver()"<<std::endl;
		}	

	protected:

		std::queue<sf::Event> eventQueue;

};




#endif