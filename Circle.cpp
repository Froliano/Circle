#include "Circle.hpp"

Circle::Circle(float x, float y, float r, sf::Color color, sf::Vector2f offset) : pos(x, y), radius(r), color(color)
{
	shape.setPosition(pos);
	shape.setRadius(radius);
	shape.setFillColor(color);

	posOffset = normalize(offset);
}

void Circle::update(sf::RenderWindow& window)
{
	pos += posOffset;
	shape.setPosition(pos);
	window.draw(shape);
}

void Circle::circleCollide(Circle circle)
{
	sf::Vector2f centerA = getCenter();
	sf::Vector2f centerB = circle.getCenter();

	sf::Vector2f offset = sf::Vector2f(centerB.x - centerA.x, centerB.y - centerA.y);
	float distance = std::sqrt(offset.x * offset.x + offset.y * offset.y);
	
	if (distance < radius + circle.radius)
	{
		sf::Vector2f normalizedOffset = normalize(offset);
		posOffset = -normalizedOffset;
	}
}

void Circle::borderCollide(sf::Vector2u windowSize)
{
	sf::Vector2f center = getCenter();
	if (center.x - radius <= 0)
	{
		posOffset.x = std::abs(posOffset.x);
	}
	if (center.y - radius <=  0)
	{
		posOffset.y = std::abs(posOffset.y);
	}
	if (center.x + radius >= windowSize.x)
	{
		posOffset.x = -std::abs(posOffset.x);
	}
	if (center.y + radius >= windowSize.y)
	{
		posOffset.y = -std::abs(posOffset.y);
	}
}

sf::Vector2f Circle::getCenter()
{
	return sf::Vector2f(pos.x + radius, pos.y + radius);
}

sf::Vector2f Circle::normalize(sf::Vector2f vector)
{
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length == 0) 
	{ 
		return sf::Vector2f(0, 0);
	}
	return sf::Vector2f(vector.x / length, vector.y / length);
}

/*void Circle::followMouse(sf::Vector2i mousePos)
{
	sf::Vector2f offset = sf::Vector2f(mousePos.x - getCenter().x, mousePos.y - getCenter().y);
	float norme = std::sqrt(offset.x * offset.x + offset.y * offset.y);
	float factor = 1 / std::abs(norme);
	offset *= factor;

	pos.x += offset.x;
	pos.y += offset.y;

	shape.setPosition(pos);

}*/