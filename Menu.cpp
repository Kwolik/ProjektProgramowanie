#include "Menu.h"


Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts\\AmaticSC-Regular.ttf"))
	{
		cout << "Nie znaleziono czcionki!";
	}

	//tekst do wy�wietlenia
	opis = "Statki c ++";

	description.setFont(font); //ustawienie fontu
	description.setFillColor(Color::Color(153,153,153,255)); //ustawienie koloru
	description.setString(opis); //przypisanie tekstu, kt�ry ma zosta� wy�wietlony
	description.setCharacterSize(1.5*fontSize); //wielko�� tekstu
	description.setPosition(Vector2f(width / 4, height / 4)); //pozycja tekstu


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

	selectedItemIndex = 0; //obecnie wybrana opcja w menu
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow &window) //rysowanie napis�w w menu
{
	window.draw(description);

	for (int i = 0; i < numberOfItems; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::Up() //poruszanie si� po menu w g�re
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}

void Menu::Down() //i w d�
{
	if (selectedItemIndex + 1 < numberOfItems)
	{
		menu[selectedItemIndex].setFillColor(Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(Color::Red);
	}
}