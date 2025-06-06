#include "Circle.hpp"

Circle::Circle(float x, float y, float r, sf::Color color) : pos(x, y), radius(r), color(color)
{
	shape.setPosition(pos);
	shape.setRadius(radius);
	shape.setFillColor(color);
}

void Circle::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void Circle::followMouse(sf::Vector2i mousePos)
{
	sf::Vector2f offset = sf::Vector2f(mousePos.x - getCenter().x, mousePos.y - getCenter().y);
	float norme = std::sqrt(offset.x * offset.x + offset.y * offset.y);
	float factor = 1 / std::abs(norme);
	offset *= factor;

	pos.x += offset.x;
	pos.y += offset.y;

	shape.setPosition(pos);
}

sf::Vector2f Circle::getCenter() const
{
	return sf::Vector2f(pos.x + radius, pos.y + radius);
}

bool Circle::isCollide(Circle& circle)
{

	float dx = this->pos.x - circle.pos.x;
	float dy = this->pos.y - circle.pos.y;
	float distance = std::sqrt(dx * dx + dy * dy);


	return distance <= (this->radius + circle.radius);
}