#pragma once

#include <SFML/Graphics.hpp>
#include "Circle.hpp"

class CollisionManager {

private:
	sf::RenderWindow& window;
	std::vector<Circle> circles;


public:
	CollisionManager(sf::RenderWindow& window);
	void drawCircles();
	void followMouse(sf::Vector2i mousePos);
};