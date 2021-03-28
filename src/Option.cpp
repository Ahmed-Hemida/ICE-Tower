#include "Option.h"

Option::Option(float width, float hight)
{
	font.loadFromFile("Blackbird.ttf");

	op[0].setFont(font);
	op[0].setFillColor(sf::Color::Blue);
	op[0].setString("Music");
	op[0].setCharacterSize(70);
    op[0].setOutlineThickness(4);
	op[0].setOutlineColor(sf::Color::Black);
	op[0].setPosition(sf::Vector2f(width / 2-375, hight / (option + 1) + 120));

	op[1].setFont(font);
	op[1].setFillColor(sf::Color::Red);
	op[1].setString("Sound");
	op[1].setCharacterSize(70);
	op[1].setOutlineThickness(4);
	op[1].setOutlineColor(sf::Color::Black);
	op[1].setPosition(sf::Vector2f(width / 2-375, hight / (option + 2) + 200));

	op[3].setFont(font);
	op[3].setFillColor(sf::Color::Red);
	op[3].setString("Back");
	op[3].setCharacterSize(70);
	op[3].setOutlineThickness(4);
	op[3].setOutlineColor(sf::Color::Black);
	op[3].setPosition(sf::Vector2f(width / 2-375, hight / (option + 4) + 350));

	op[2].setFont(font);
	op[2].setFillColor(sf::Color::Red);
	op[2].setString("Charcter");
	op[2].setCharacterSize(70);
	op[2].setOutlineThickness(4);
	op[2].setOutlineColor(sf::Color::Black);
	op[2].setPosition(sf::Vector2f(width / 2 - 375, hight / (option + 3) + 275));


	optionselect = 0;
}

Option::~Option()
{
}

void Option::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(op[i]);
	}
}

void Option::moveup()
{
	if (optionselect - 1 >= -1)
	{
		op[optionselect].setFillColor(sf::Color::Red);
		op[optionselect].setOutlineColor(sf::Color::Black);
		optionselect--;
		if (optionselect == -1) {
			optionselect = 3;
		}
		op[optionselect].setFillColor(sf::Color::Blue);
		op[optionselect].setOutlineColor(sf::Color::Black);
	}
}

void Option::movedown()
{
	if (optionselect + 1 <= option)
	{
		op[optionselect].setFillColor(sf::Color::Red);
		op[optionselect].setOutlineColor(sf::Color::Black);
		optionselect++;
		if (optionselect == 4) {
			optionselect = 0;
		}
		op[optionselect].setFillColor(sf::Color::Blue);
		op[optionselect].setOutlineColor(sf::Color::Black);
	}
}

void Option::open()
{


}
