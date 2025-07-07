#include "CollisionManager.hpp"

CollisionManager::CollisionManager(sf::RenderWindow& window) : window(window)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> speed(-5, 5);
	std::uniform_int_distribution<> size(10, 100);
	std::uniform_int_distribution<> quantity(2, 6);
	std::uniform_int_distribution<> posX(100, 700);
	std::uniform_int_distribution<> posY(100, 500);
	std::uniform_int_distribution<> color(0, 24);

	for (int i = 0; i < quantity(gen); i++)
	{
		circles.push_back(Circle(posX(gen), posY(gen), size(gen), colorList[color(gen)], sf::Vector2f(speed(gen), speed(gen))));

	}
};

void CollisionManager::drawCircles()
{
	for (auto& circle : circles)
	{
		circle.borderCollide(window.getSize());
		for (auto& otherCircle : circles)
		{
			if (&circle != &otherCircle)
			{
				circle.circleCollide(otherCircle, window);
			}
		}
	}
	for (auto& circle : circles)
	{
		circle.update(window);
	}
};