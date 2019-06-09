#include "Game.h"


using namespace sf;
using namespace std;

int main()
{
	int okno = 0;

	RenderWindow window(VideoMode(1920, 1080), "Statki"); //uwtorzenie okna
	Menu menu(window.getSize().x, window.getSize().y);
	Game game(window.getSize().x, window.getSize().y);


	while (window.isOpen())
	{
		Event event;
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
						okno=1;
						break;
					case 1:
						window.close();
						okno=0;
						break;
					}

				}
			}
		

		}

		window.clear(Color::Black);

		if(okno == 0)
			menu.draw(window);
									//przechodzenie miedzy scenami (dopracowac jak starczy czas)
		if(okno == 1)
			game.draw(window);
		window.display();

	}

	return 0;
}
