#pragma once
#include "Menu.h"

using namespace sf;

class Game
{
public:
	Game(float width, float height);
	~Game();

	void draw(RenderWindow &window);

private:
	Sprite fieldSprite1; //utworzenie obrazka
	Sprite fieldSprite2;
	Texture fieldTexture; //uwtorzenie tekstury
	int fieldSize = 800;
};

