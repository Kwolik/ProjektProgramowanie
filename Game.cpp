#include "Game.h"

RenderWindow window(VideoMode(1980, 1280), "Statki");

Game::Game(float width, float height)
{
	if (!font.loadFromFile("Fonts\\AmaticSC-Regular.ttf"))
	{
		cout << "Nie znaleziono czcionki!";
	}

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

	/*	<--		Wspó³rzêdne		-->*/
	for (int j = 0; j < 2; j++)
	{

		int k = kratkaSprite2.getPosition().x - kratkaSprite2.getOrigin().x;

		for (int i = 0; i < textNumber; i++)
		{
			text1[i][j].setFont(font);
			text1[i][j].setFillColor(Color::White);
			text1[i][j].setString(char(65 + i));
			text1[i][j].setCharacterSize(fontSize);
			text1[i][j].setPosition(Vector2f(width / 2 - 500 - fieldSize / 2 - fontSize * 3 / 4 + j*(k - fieldSize / 15), height / 2 - fieldSize / 2 + fieldSize / 10 * i));
		}
		for (int i = 0; i < textNumber; i++)
		{
			text2[i][j].setFont(font);
			text2[i][j].setFillColor(Color::White);
			text2[i][j].setString(char(49 + i));
			text2[i][j].setCharacterSize(fontSize);
			text2[i][j].setPosition(Vector2f(width / 2 - 500 - fieldSize / 2 + fieldSize / 25 + fieldSize / 10 * i + j*(k - fieldSize / 13), height / 2 - fieldSize / 2 - fieldSize / 10));
			text2[9][j] = text2[8][j];
			text2[9][j].setPosition(text2[8][j].getPosition().x + fieldSize / 10, text2[8][j].getPosition().y);
			text2[9][j].setString(string("10"));
		}
	}
	

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

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < textNumber; i++)
		{
			window.draw(text1[i][j]);
			window.draw(text2[i][j]);
		}
	}

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