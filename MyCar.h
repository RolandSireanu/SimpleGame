#ifndef MYCAR_H
#define MYCAR_H

#include "IObserver.h"

class MyCarComponent : public IObserver
{

	public:	

		MyCarComponent(IOSubject& subject) : IObserver(subject)
		{
			if(!myCarTexture.loadFromFile("car.png" , sf::IntRect(47,30, 80,195)))
			{
				std::cout<<"ERROR : Can't load my car !"<<std::endl;
			}

			myCar.setTexture(myCarTexture);
			myCar.setScale(0.75,0.75);

			resetToDefault();

		}


		void update(sf::RenderWindow& window)
		{

			//std::queue<sf::Event> eventQueue;

			while(!eventQueue.empty())
			{

				sf::Event tempEvent = eventQueue.front();
				eventQueue.pop();

				if(tempEvent.type == sf::Event::KeyPressed)
				{
					if(tempEvent.key.code == sf::Keyboard::Left)
					{
						myCar.setPosition(MYCAR_DEFAULT_X , MYCAR_DEFAULT_Y);
					}
					else if(tempEvent.key.code == sf::Keyboard::Right)
					{
						myCar.setPosition(MYCAR_RIGHT_POSITION , MYCAR_DEFAULT_Y);	
					}	
				}
			}


			/*sf::Event event ;

			if(window.pollEvent(event))
			{	
				switch(event.type)
				{
					case sf::Event::KeyPressed:
					{
						if(event.key.code == sf::Keyboard::Left)
						{				
							myCar.setPosition(MYCAR_DEFAULT_X , MYCAR_DEFAULT_Y);
						}
						else if(event.key.code == sf::Keyboard::Right)
						{
							myCar.setPosition(MYCAR_RIGHT_POSITION , MYCAR_DEFAULT_Y);	
						}				

						break;
					}

					default :
						break;

				}	
			}
			*/

			window.draw(myCar);

		}


		sf::Sprite& getMyCar()
		{
			return myCar;
		}


		void addEventToQ(sf::Event ev)
		{
			eventQueue.push(ev);
		}

	private:

		void resetToDefault()
		{
			myCar.setPosition(MYCAR_DEFAULT_X , MYCAR_DEFAULT_Y);			
		}

		const float MYCAR_DEFAULT_X = 380.f;
		const float MYCAR_DEFAULT_Y = 600.f;
		const float MYCAR_RIGHT_POSITION = 590.f;
		sf::Texture myCarTexture;
		sf::Sprite myCar;

};



#endif