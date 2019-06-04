#include "Game.h"
#include <string>

using namespace sf;
using namespace std;

int main()
{
	Sprite backgroundSprite;
	Texture backgroundTexture;
	backgroundTexture.loadFromFile("Pictures\\Background.png");
	backgroundTexture.setSmooth(true);
	backgroundSprite.setTexture(backgroundTexture);


	RenderWindow window(VideoMode(1980, 1280), "Statki");
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
	
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();

			case Event::KeyPressed:
				switch (event.key.code)
				{
				case Keyboard::Escape:
					window.close();
					break;
				}

			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up:
					menu.Up();						
					break;
					
				case Keyboard::Down:
					menu.Down();
					break;

				case Keyboard::Return:
				case Keyboard::Space:
					switch (menu.PressedItem())
					{
					case 0:
						cout << "Graj!" << endl;
						break;
					case 1:
						window.close();
						break;
					}

				}
			}
			break;

		}

		window.clear(Color::Black);
		menu.draw(window);
		//window.draw(backgroundSprite);
		window.display();
	}

	return 0;
}