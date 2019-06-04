#include "Menu.h"

//C:\\Windows\\Fonts\\

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts\\AmaticSC-Regular.ttf"))
	{
		cout << "Nie znaleziono czcionki!";
	}

	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("Graj");
	menu[0].setCharacterSize(fontSize);
	menu[0].setPosition(Vector2f(width / 2, height / 2));

	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Koniec gry");
	menu[1].setCharacterSize(fontSize);
	menu[1].setPosition(Vector2f(width / 2, height / 2 + fontSize*2));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window)
{
	for (int i = 0; i < numberOfItems; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::Up()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::Down()
{
	if (selectedItemIndex + 1 < numberOfItems)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}