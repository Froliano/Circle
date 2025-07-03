#include "CollisionManager.hpp"

CollisionManager::CollisionManager(sf::RenderWindow& window) : window(window)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(-50, 50);

	circles.push_back(Circle(50, 50, 50, sf::Color::Blue, sf::Vector2f(distrib(gen), distrib(gen))));
	circles.push_back(Circle(15, 50, 50, sf::Color::Red, sf::Vector2f(distrib(gen), distrib(gen))));
	circles.push_back(Circle(100, 300, 10, sf::Color::Yellow, sf::Vector2f(distrib(gen), distrib(gen))));
	circles.push_back(Circle(600, 500, 150, sf::Color::Cyan, sf::Vector2f(distrib(gen), distrib(gen))));

};

void CollisionManager::drawCircles()
{
	for (auto& circle : circles)
	{
		circle.update(window);
		circle.borderCollide(window.getSize());
		for (auto& otherCircle : circles)
		{
			if (&circle != &otherCircle)
			{
				circle.circleCollide(otherCircle);
			}
		}
	}
};

/*void CollisionManager::followMouse(sf::Vector2i mousePos)
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
}*/