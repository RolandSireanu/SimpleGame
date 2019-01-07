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
				for(sf::Sprite &car : cars)
				{
					//Read the current position and size
					sf::Vector2f position = car.getPosition();
					sf::Vector2f scale 	  = car.getScale();

					//Increase position and size
					position.x -= ENEMY_X_MOVE;
					position.y += ENEMY_Y_MOVE;
					scale.x += 0.011;
					scale.y += 0.011;

					if(outOfScreen(position , window))
					{
						position.x = ENEMY_X_LEFT;
						position.y = ENEMY_Y_LEFT;
						scale.x = ENEMY_DEFAULT_SCALE;
						scale.y = ENEMY_DEFAULT_SCALE;						
					}

					//Set new position and size
					car.setPosition(position);
					car.setScale(scale);

					#ifdef DEBUG
						std::cout<<"position = "<<position.x<<" , "<<position.y<<std::endl;
						std::cout<<"scale = "<<scale.x<<" , "<<scale.y<<std::endl;
					#endif

					window.draw(car);
				}

				//Update 
			}
			else
			{
				for(const sf::Sprite &car : cars)
				{
					window.draw(car);
				}				
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
			cars.clear();

			sf::Sprite temp;
			temp.setTexture(carTexture);
			temp.setPosition(ENEMY_X_LEFT , ENEMY_Y_LEFT);
			temp.setScale(ENEMY_DEFAULT_SCALE , ENEMY_DEFAULT_SCALE);
			cars.push_back(temp);

			#ifdef DEBUG
				std::cout<<"Size of cars vector = "<<cars.size()<<std::endl;
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

		const float ENEMY_X_LEFT = 475.f;
		const float ENEMY_Y_LEFT = 68.f;
		const float ENEMY_X_RIGHT = 549.f; 
		const float ENEMY_Y_RIGHT = 68.f;
		const float ENEMY_DEFAULT_SIZE_X = 11;
		const float ENEMY_DEFAULT_SIZE_Y = 20;
		const float ENEMY_DEFAULT_SCALE = 0.10f;
		const float ENEMY_X_MOVE = 2.7f;
		const float ENEMY_Y_MOVE = 10.f;

};


#endif