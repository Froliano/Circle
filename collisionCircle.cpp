#include <SFML/Graphics.hpp>
#include "CollisionManager.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "circle");

	CollisionManager collisionManager(window);

	window.setFramerateLimit(60);

	bool mousePressed = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
				mousePressed = true;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                mousePressed = false;
            }
        }

		/*if (mousePressed)
		{
			collisionManager.followMouse(sf::Mouse::getPosition(window));
		}*/


		window.clear(sf::Color::Black);
		collisionManager.drawCircles();
		window.display();
    }

}