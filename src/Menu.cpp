#include "Menu.h"

Menu::Menu(float width, float hight)
{
	font.loadFromFile("Blackbird.ttf");

	main[0].setFont(font);
	main[0].setFillColor(sf::Color::Red);
	main[0].setString("Play");
	main[0].setCharacterSize(70);
	main[0].setOutlineThickness(4);
	main[0].setOutlineColor(sf::Color::Black);
	main[0].setPosition(sf::Vector2f(width / 2-375 , hight / (maxmenu + 1) + 125));

	main[1].setFont(font);
	main[1].setFillColor(sf::Color::Black);
	main[1].setString("Option");
	main[1].setCharacterSize(70);
	main[1].setOutlineThickness(4);
	main[1].setOutlineColor(sf::Color::Blue);
	main[1].setPosition(sf::Vector2f(width / 2-375 , hight / (maxmenu + 2) + 225));

	main[2].setFont(font);
	main[2].setFillColor(sf::Color::Black);
	main[2].setString("Exit");
	main[2].setCharacterSize(70);
	main[2].setOutlineThickness(4);
	main[2].setOutlineColor(sf::Color::Blue);
	main[2].setPosition(sf::Vector2f(width / 2 -375, hight / (maxmenu + 3) + 325));

	menuselected = 0;

}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow& window)
{
	for (int i =0; i < 3; i++)
	{
		 window.draw(main[i]);
	}
}

void Menu::moveup()
{
	if (menuselected -1 >= -1)
	{
		main[menuselected].setFillColor(sf::Color::Black);
		main[menuselected].setOutlineColor(sf::Color::Blue);
		menuselected--;
		if (menuselected == -1) {
			menuselected = 2;
		}
		main[menuselected].setFillColor(sf::Color::Red);
		main[menuselected].setOutlineColor(sf::Color::Black);
	}

}

void Menu::movedown()
{
	if (menuselected + 1 <= maxmenu)
	{
		main[menuselected].setFillColor(sf::Color::Black);
		main[menuselected].setOutlineColor(sf::Color::Blue);
		menuselected++;
		if (menuselected == 3) {
			menuselected = 0;
		}
		main[menuselected].setFillColor(sf::Color::Red);
		main[menuselected].setOutlineColor(sf::Color::Black);
	}
}


