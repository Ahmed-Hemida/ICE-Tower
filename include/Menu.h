#pragma once
#include<SFML/Graphics.hpp>
#define maxmenu 3
class Menu
{
public:
	Menu(float hight ,float width);
	~Menu();
	void Draw(sf::RenderWindow& window);
	void moveup();
	void movedown();

 int menuselected;


private:

	sf::Font font;
	sf::Text main [maxmenu];

};

