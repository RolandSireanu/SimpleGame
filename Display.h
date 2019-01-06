#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;

#define ROWS 768
#define COLS 1024

class DisplayComponent : public vector<sf::Vertex>
{
	public:

		DisplayComponent(const DisplayComponent&) = delete;							//Copy constructor
		DisplayComponent(const DisplayComponent&&) = delete;							//Move constructor
		DisplayComponent() : verticiesCounter(0)	, firstFrame(true)			//Default constructor 
		{
			SetDefaultLines();
			tempCounter = 0 ;
		}


		void AddVertex(sf::Vertex vertex)
		{
			verticiesCounter++;
			push_back(vertex);
		}

		sf::Vertex* GetArrayOfVerticies()
		{
			return data();
		}

		int& GetNrOfVerticies()
		{
			return verticiesCounter;
		}	

		void update()
		{			
			tempCounter++;
			if(tempCounter % 10 == 0)
			{
				if(firstFrame)
				{				
					SetFirstFrameLines();
				}
				else
				{				
					SetSecondFrameLines();
				}
				firstFrame = !firstFrame;			
			}
		}	

	private:

		int verticiesCounter;
		bool firstFrame;
		int tempCounter;

		void SetDefaultLines()
		{
			AddVertex(sf::Vertex(sf::Vector2f(256 , ROWS)));
			AddVertex(sf::Vertex(sf::Vector2f(512-25, 0)));
			AddVertex(sf::Vertex(sf::Vector2f(ROWS , ROWS)));
			AddVertex(sf::Vertex(sf::Vector2f(512+25 , 0)));

			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-192)));
			//192 -> 384 = free space
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-384)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-384-96)));
			//
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-576)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-576-48)));
			//
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-672)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-672-24)));
			//
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-720)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-720-12)));
			//
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-744)));
			AddVertex(sf::Vertex(sf::Vector2f(512 , ROWS-744-6)));
		}

		void SetFirstFrameLines()
		{
			

			at(4) = (sf::Vertex(sf::Vector2f(512 , ROWS)));
			at(5) = (sf::Vertex(sf::Vector2f(512 , ROWS-192)));
			//192 -> 384 = free space
			at(6) = (sf::Vertex(sf::Vector2f(512 , ROWS-384)));
			at(7) = (sf::Vertex(sf::Vector2f(512 , ROWS-384-96)));
			//
			at(8) = (sf::Vertex(sf::Vector2f(512 , ROWS-576)));
			at(9) = (sf::Vertex(sf::Vector2f(512 , ROWS-576-48)));

			at(10) = (sf::Vertex(sf::Vector2f(512 , ROWS-672)));
			at(11) = (sf::Vertex(sf::Vector2f(512 , ROWS-672-24)));

			at(14) = (sf::Vertex(sf::Vector2f(512 , ROWS-744)));
			at(15) = (sf::Vertex(sf::Vector2f(512 , ROWS-744-6)));
						
		}

		void SetSecondFrameLines()
		{

			at(4) = (sf::Vertex(sf::Vector2f(512 , ROWS-192)));
			at(5) = (sf::Vertex(sf::Vector2f(512 , ROWS-384)));
			//192 -> 384 = free space
			at(6) = (sf::Vertex(sf::Vector2f(512 , ROWS-384-96)));
			at(7) = (sf::Vertex(sf::Vector2f(512 , ROWS-384-96-48)));
			//
			at(8) = (sf::Vertex(sf::Vector2f(512 , ROWS-576-48)));
			at(9) = (sf::Vertex(sf::Vector2f(512 , ROWS-576-48-24)));
			//
			at(10) = (sf::Vertex(sf::Vector2f(0,0)));
			at(11) = (sf::Vertex(sf::Vector2f(0,0)));

			at(14) = (sf::Vertex(sf::Vector2f(0,0)));
			at(15) = (sf::Vertex(sf::Vector2f(0,0)));
		}
};

#endif