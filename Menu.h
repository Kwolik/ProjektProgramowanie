#pragma once
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#define numberOfItems 2

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(RenderWindow &window);
	void Up();
	void Down();
	int PressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	int fontSize = 60;
	Font font;
	Text menu[numberOfItems];
	Text description;
	string opis;
};

