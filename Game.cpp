#include "Game.h"

RenderWindow window(VideoMode(1980, 1280), "Statki");

Game::Game(float width, float height)
{
	/*	<--		Pole		-->*/
	fieldTexture.loadFromFile("Pictures\\Field.png"); //wgranie tekstury
	//fieldTexture.setSmooth(true);
	
	fieldSprite1.setTexture(fieldTexture); //przypisanie tekstury do obrazka
	fieldSprite1.setOrigin(fieldSize / 2, fieldSize / 2);
	fieldSprite1.setPosition(width / 2 - 500, height / 2); //pozycja obrazka
	
	fieldSprite2.setTexture(fieldTexture);
	fieldSprite2.setOrigin(fieldSize / 2, fieldSize / 2);
	fieldSprite2.setPosition(width / 2 + 500, height / 2);

	/*	<--		Obramowanie		-->*/
	/*borderTexture.loadFromFile("Pictures\\Border.png");
	borderTexture.setRepeated(true);

	borderSprite.setPosition(width / 2 - 500 - 16, height / 2 - 16);
	borderSprite.setTextureRect({ 0, 0, fieldSize + 32, fieldSize + 32 });
	borderSprite.setOrigin(fieldSize / 2, fieldSize / 2);
	borderSprite.setTexture(borderTexture);*/

	/*	<--			T³o			-->*/
	backgroundTexture.loadFromFile("Pictures\\Background.png");
	backgroundTexture.setRepeated(true);

	backgroundSprite.setTextureRect({ 0, 0, int(width), int(height) });
	backgroundSprite.setTexture(backgroundTexture);

	/*	<--		Kratka		-->*/
	kratkaTexture.loadFromFile("Pictures\\Kratka.png");
	kratkaTexture.setRepeated(true);

	kratkaSprite1.setTexture(kratkaTexture);
	kratkaSprite1.setOrigin(fieldSize / 2, fieldSize / 2);
	kratkaSprite1.setPosition(width / 2 - 500, height / 2);
	kratkaSprite1.setTextureRect({ 0, 0, fieldSize, fieldSize});

	kratkaSprite2 = kratkaSprite1;
	kratkaSprite2.setPosition(width / 2 + 500, height / 2);

	//stan = Menu;
}

Game::~Game()
{
}



void Game::draw(RenderWindow &window) //wyœwietlenie obrazków
{
	window.draw(backgroundSprite);
	//window.draw(borderSprite);
	window.draw(fieldSprite1);
	window.draw(fieldSprite2);
	window.draw(kratkaSprite1);
	window.draw(kratkaSprite2);

}
/*
void Game::startGry()
{
	while (stan != Koniec)
	{
		switch (stan)
		{
		case Menu:
		{
			menu();
		}break;

		case Gra:
		{

		}break;
		}
	}
}

void Game::menu()
{

}
*/