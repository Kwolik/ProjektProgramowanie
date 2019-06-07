#include "Game.h"



Game::Game(float width, float height)
{
	fieldTexture.loadFromFile("Pictures\\Field.png"); //wgranie tekstury
	//fieldTexture.setSmooth(true);
	
	fieldSprite1.setTexture(fieldTexture); //przypisanie tekstury do obrazka
	fieldSprite1.setOrigin(fieldSize / 2, fieldSize / 2);
	fieldSprite1.setPosition(width / 2 - 500, height / 2); //pozycja obrazka
	
	fieldSprite2.setTexture(fieldTexture);
	fieldSprite2.setOrigin(fieldSize / 2, fieldSize / 2);
	fieldSprite2.setPosition(width / 2 + 500, height / 2);


}

Game::~Game()
{
}

void Game::draw(RenderWindow &window) //wyœwietlenie obrazków
{
	
	window.draw(fieldSprite1);
	window.draw(fieldSprite2);
}