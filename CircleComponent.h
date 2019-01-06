#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Display.h"

class CircleComponent
{
	public:

		
		CircleComponent(const CircleComponent&) = delete;
		CircleComponent(const CircleComponent&&) = delete;
		CircleComponent()
		{
			sf::RectangleShape tempRectangle = sf::RectangleShape();
			
			if(!texture.loadFromFile("EnemyCar.png" , sf::IntRect(180,140 , 270,310)))
			{
				std::cout<<"Can't load the enemyCar image !!!"<<std::endl;
			}
			

			tempRectangle.setSize(sf::Vector2f(RECTANGLE_DEFAULT_SIZE_X , RECTANGLE_DEFAULT_SIZE_Y));

			tempRectangle.setTexture(&texture);
			tempRectangle.setFillColor(sf::Color(128,255,128));
			rectangles.push_back(tempRectangle);

			ResetToDefault();
		}


		void update(bool wasCollision)
		{
			if(wasCollision)
			{
				ResetToDefault();				
			}
			else
			{
				if(counter % 2 == 0)
				{
					//radiusCnt += RADIUS_INC;
					xSize += RECTANGLE_X_INC;
					ySize += RECTANGLE_Y_INC;
					xCount -= RECTANGLE_X_MOVE;
					yCount += RECTANGLE_Y_MOVE;
				
				if(yCount > ROWS)
				{
					xCount = RECTANGLE_DEFAULT_X;
					yCount = RECTANGLE_DEFAULT_Y;
					xSize  = RECTANGLE_DEFAULT_SIZE_X;
					ySize  = RECTANGLE_DEFAULT_SIZE_Y;
					//radiusCnt = RADIUS;
				}

				}
				
				rectangles[0].setPosition(xCount , yCount);				
				rectangles[0].setSize(sf::Vector2f(xSize , ySize));
				//rectangles[0].setRadius(radiusCnt);

				counter++;
			}
		}

		sf::RectangleShape getRectangle()
		{
			return rectangles[0];
		}

	private:
		std::vector<sf::RectangleShape> rectangles;
		//const float RADIUS_INC = 1.5f;
		const float RECTANGLE_X_INC = 4;
		const float RECTANGLE_Y_INC = 4;
		const float RECTANGLE_DEFAULT_X = 475.f;
		const float RECTANGLE_DEFAULT_Y = 68.f;
		const float RECTANGLE_DEFAULT_SIZE_X = 11;
		const float RECTANGLE_DEFAULT_SIZE_Y = 20;
		const float RECTANGLE_X_MOVE = 2.7f;
		const float RECTANGLE_Y_MOVE = 10.f;
		const float RECTANGLE_INCREASE = 10.f;		

		sf::Texture texture;

		float xCount;
		float yCount;
		float xSize;
		float ySize;
		//float radiusCnt;
		unsigned int counter;

		void ResetToDefault()
		{
			xCount = RECTANGLE_DEFAULT_X;
			yCount = RECTANGLE_DEFAULT_Y;
			xSize  = RECTANGLE_DEFAULT_SIZE_X;
			ySize  = RECTANGLE_DEFAULT_SIZE_Y;			
			//radiusCnt = RADIUS;
			counter = 0;
			
			rectangles[0].setPosition(RECTANGLE_DEFAULT_X , RECTANGLE_DEFAULT_Y);
			rectangles[0].setSize(sf::Vector2f(xSize , ySize));
			//rectangles[0].setRadius(RADIUS);
		}
};

#endif