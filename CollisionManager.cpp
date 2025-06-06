#include "CollisionManager.hpp"

CollisionManager::CollisionManager(sf::RenderWindow& window) : window(window)
{
	circles.push_back(Circle(100, 300, 50, sf::Color::Red));
	circles.push_back(Circle(600, 100, 120, sf::Color::Blue));
	circles.push_back(Circle(400, 250, 50, sf::Color::Yellow));
};

void CollisionManager::drawCircles()
{
	for (auto& circle : circles)
	{
		circle.draw(window);
	}
};

void CollisionManager::followMouse(sf::Vector2i mousePos)
{
	for (auto& circleA : circles)
	{
		bool follow = true;
		for (auto& circleB : circles)
		{
			if (&circleA != &circleB)
			{
				if (circleA.isCollide(circleB))
				{
					follow = false;
				}
			}
		}
		if (follow)
			circleA.followMouse(mousePos);
	}
}