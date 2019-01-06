#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "SFML/Graphics.hpp"


class RectangleComponent
{

	public:

		RectangleComponent(float arg1 , float arg2) : rectangleShape(sf::Vector2f(arg1 , arg2))
		{			
			//rectangleShape.setFillColor(sf::Color(100,25,125));

			if(!texture.loadFromFile("car.png" , sf::IntRect(47,30,80,195)))
			{
				std::cout<<"Can't load the texture !!!"<<std::endl;
			}

			rectangleShape.setTexture(&texture , true);

			update(true);
		}

		void update(bool onLeft)
		{
			if(onLeft)
			{
				rectangleShape.setPosition(RECTANGLE_DEFAULT_X , RECTANGLE_DEFAULT_Y);
			}
			else
			{
				rectangleShape.setPosition(RECTANGLE_RIGHT_POSITION , RECTANGLE_DEFAULT_Y);
			}
		}

		sf::RectangleShape getRectangle()
		{
			return rectangleShape;
		}

	private:

		sf::RectangleShape rectangleShape;
		const float RECTANGLE_DEFAULT_X = 380.f;
		const float RECTANGLE_DEFAULT_Y = 600.f;
		const float RECTANGLE_RIGHT_POSITION = 590.f;
		sf::Texture texture;

};



#endif