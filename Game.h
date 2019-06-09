#pragma once
#include "Menu.h"

using namespace sf;

class Game
{
public:
	Game(float width, float height);
	~Game();

	//void startGry();
	void draw(RenderWindow &window);


private:
	Sprite fieldSprite1; //utworzenie obrazka
	Sprite fieldSprite2;
	Texture fieldTexture; //uwtorzenie tekstury

	Sprite borderSprite; //ramka
	Texture borderTexture;

	Sprite backgroundSprite; //t³o
	Texture backgroundTexture;

	Sprite kratkaSprite1;
	Sprite kratkaSprite2;
	Texture kratkaTexture;

	int fieldSize = 800;

	/*enum stanyGry{Menu, Gra, Koniec};
	stanyGry stan;
	void menu();*/
};
