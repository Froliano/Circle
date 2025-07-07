#include "Circle.hpp"
#include <thread>
#include <chrono>

Circle::Circle(float x, float y, float r, sf::Color color, sf::Vector2f offset) : pos(x, y), radius(r), color(color)
{
	shape.setPosition(pos);
	shape.setRadius(radius);
	shape.setFillColor(color);

	posOffset = offset;
	vitesse = offset;
	std::cout << "Circle created at position: (" << posOffset.x << ", " << posOffset.y << ") with radius: " << radius << std::endl;
}

void Circle::update(sf::RenderWindow& window)
{
	pos += posOffset;
	vitesse = posOffset;
	shape.setPosition(pos);
	window.draw(shape);
}

void Circle::circleCollide(Circle& circle, sf::RenderWindow& window)
{
	sf::Vector2f centerA = getCenter();
	sf::Vector2f centerB = circle.getCenter();

	float distance = std::sqrt(((centerB.x - centerA.x) * (centerB.x - centerA.x)) + ((centerB.y - centerA.y) * (centerB.y - centerA.y)));
	
	if (distance < radius + circle.radius)
	{

		// vecteur qui défini la direction du rebond
		sf::Vector2f normal = sf::Vector2f(centerA.x - centerB.x, centerA.y - centerB.y);
		normal = normalize(normal);

		//vitesse relative du cercle par rapport au objects autour
		sf::Vector2f relativeVelocity = vitesse - circle.vitesse;

		// Vérifier si les cercles se rapprochent
		float dotProduct = normal.x * relativeVelocity.x + normal.y * relativeVelocity.y;
		if (dotProduct > 0) return;

		// Calculer la nouvelle vitesse après collision
		float restitution = 0.5f; // Coefficient de restitution pour la collision
		float impulsion = (-(1 + restitution) * dotProduct) / (1/radius + 1/circle.radius);

		// Appliquer la nouvelle vitesse
		posOffset = vitesse + sf::Vector2f(((impulsion / radius) * normal.x), ((impulsion / radius) * normal.y));
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
