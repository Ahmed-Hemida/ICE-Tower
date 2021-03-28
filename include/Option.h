#pragma once
#include<SFML/Graphics.hpp>
#include<sstream>
#define option 4
class Option
{

	public:
		Option(float width, float hight);
		~Option();
		void Draw(sf::RenderWindow& window);
		void moveup();
		void movedown();
		void open();
		int optionselect;

	private:

		sf::Font font;
		sf::Text op[option];


};

