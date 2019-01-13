#ifndef ENEMY_CARS_H
#define ENEMY_CARS_H

#include "SFML/Graphics.hpp"
#include <vector>
#include <iostream>

class EnemyCarsComponent
{
	public:

		EnemyCarsComponent()
		{
			updateCounter = 0;

			if(!carTexture.loadFromFile("EnemyCar.png" , sf::IntRect(180,140 , 270,310)))
			{
				std::cout<<"ERROR : Can't load enemycar !"<<std::endl;
			}

			resetToDefault();

		}

		void update(sf::RenderWindow &window)
		{
			if(updateCounter % 2 == 0)
			{
				//Update every cars position and size				
				//Read the current position and size
				sf::Vector2f position = car->getPosition();
				sf::Vector2f scale 	  = car->getScale();

				//As near is to my car , it will increase faster 
				ENEMY_Y_MOVE += 0.55f;
				ENEMY_SCALE_X += ENEMY_SCALE_FACTOR;
				ENEMY_SCALE_Y += ENEMY_SCALE_FACTOR;

				//Increase position and size
				position.x -= ENEMY_X_MOVE;
				position.y += ENEMY_Y_MOVE;
				scale.x += ENEMY_SCALE_FACTOR;
				scale.y += ENEMY_SCALE_FACTOR;

				#ifdef DEBUG
					std::cout<<"ENEMY_SCALE_X = "<<ENEMY_SCALE_X<<" ENEMY_SCALE_Y = "<<ENEMY_SCALE_Y<<std::endl;
				#endif


				if(outOfScreen(position , window))
				{	
					resetToDefault();
					
					#ifdef DEBUG						
						std::cout<<"scale.x = "<<scale.x<<" scale.y = "<<scale.y<<std::endl;
					#endif						
																
					ENEMY_SCALE_X = ENEMY_DEFAULT_SCALE;
					ENEMY_SCALE_Y = ENEMY_DEFAULT_SCALE;
					ENEMY_Y_MOVE = 10.f;					
					
				}
				else
				{
					//Set new position and size
					car->setPosition(position);
					car->setScale(scale);
				}

				#ifdef DEBUG
					std::cout<<"position = "<<position.x<<" , "<<position.y<<std::endl;
					std::cout<<"scale = "<<scale.x<<" , "<<scale.y<<std::endl;
				#endif

				window.draw(*car);				
			}
			else
			{				
					window.draw(*car);				
			}

			updateCounter++;

		}

		constexpr const vector<sf::Sprite>& getEnemyCars()
		{
			return cars;
		}

	private:

		void resetToDefault()
		{			
			//if(car != nullptr)
				//delete car;
			car = new(memArea) sf::Sprite();
			car->setTexture(carTexture);
			car->setPosition(ENEMY_X_LEFT , ENEMY_Y_LEFT);
			car->setScale(ENEMY_DEFAULT_SCALE , ENEMY_DEFAULT_SCALE);

			#ifdef DEBUG
				//std::cout<<"Size of cars vector = "<<cars.size()<<std::endl;
			#endif

		}

		bool outOfScreen(const sf::Vector2f& p , const sf::RenderWindow& w)
		{
			unsigned int ySize = w.getSize().y;
			if(p.y > ySize)
				return true;
			else
				return false;
		}


		vector<sf::Sprite> cars;
		sf::Texture carTexture;
		int updateCounter;

		unsigned char* memArea = new unsigned char[sizeof(sf::Sprite)*5];
		const float ENEMY_X_LEFT = 475.f;
		const float ENEMY_Y_LEFT = 68.f;
		const float ENEMY_X_RIGHT = 549.f; 
		const float ENEMY_Y_RIGHT = 68.f;
		const float ENEMY_DEFAULT_SIZE_X = 11;
		const float ENEMY_DEFAULT_SIZE_Y = 20;
		const float ENEMY_DEFAULT_SCALE = 0.10f;
		const float ENEMY_X_MOVE = 2.7f;
		const float ENEMY_SCALE_FACTOR = 0.020f;
		float ENEMY_Y_MOVE = 10.f;
		float ENEMY_SCALE_X = 0.011f;
		float ENEMY_SCALE_Y = 0.011f;
		sf::Sprite* car = nullptr;


};


#endif