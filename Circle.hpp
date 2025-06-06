#include <SFML/Graphics.hpp>
#include <iostream>


class Circle
{
private:
	sf::Vector2f pos;
	float radius;
	sf::CircleShape shape;
	sf::Color color;

	sf::Vector2f getCenter() const;

public:

	Circle(float x, float y, float r, sf::Color color);
	void draw(sf::RenderWindow& window);
	void followMouse(sf::Vector2i mousePos);
	bool isCollide(Circle& circle);
};