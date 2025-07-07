#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class Circle
{
private:
	sf::Vector2f pos;
	float radius;
	sf::CircleShape shape;
	sf::Color color;
	sf::Vector2f posOffset;
	sf::Vector2f vitesse;

	sf::Vector2f getCenter();
	sf::Vector2f normalize(sf::Vector2f vector);

public:

	Circle(float x, float y, float r, sf::Color color, sf::Vector2f offset);
	void update(sf::RenderWindow& window);
	void borderCollide(sf::Vector2u windowSize);
	void circleCollide(Circle& circle, sf::RenderWindow& window);
};