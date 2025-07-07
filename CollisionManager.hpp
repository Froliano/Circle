#pragma once

#include <SFML/Graphics.hpp>
#include "Circle.hpp"

class CollisionManager {

private:
	sf::RenderWindow& window;
	std::vector<Circle> circles;
    std::vector<sf::Color> colorList = {
        sf::Color(255, 165,   0),   // Orange
        sf::Color(255, 192, 203),   // Pink
        sf::Color(128,   0, 128),   // Purple
        sf::Color(0, 255,   0),   // Lime
        sf::Color(0, 128, 128),   // Teal
        sf::Color(0,   0, 128),   // Navy
        sf::Color(128, 128,   0),   // Olive
        sf::Color(128,   0,   0),   // Maroon
        sf::Color(165,  42,  42),   // Brown
        sf::Color(250, 128, 114),   // Salmon
        sf::Color(75,   0, 130),   // Indigo
        sf::Color(255, 215,   0),   // Gold
        sf::Color(192, 192, 192),   // Silver
        sf::Color(255, 127,  80),   // Coral
        sf::Color(210, 105,  30),   // Chocolate
        sf::Color(220,  20,  60),   // Crimson
        sf::Color(64, 224, 208),   // Turquoise
        sf::Color(238, 130, 238),   // Violet
        sf::Color(135, 206, 235),   // Sky Blue
        sf::Color(144, 238, 144),   // Light Green
        sf::Color(0, 100,   0),   // Dark Green
        sf::Color(139,   0,   0),   // Dark Red
        sf::Color(211, 211, 211),   // Light Grey
        sf::Color(105, 105, 105),   // Dark Grey
        sf::Color(245, 245, 220),   // Beige
    };


public:
	CollisionManager(sf::RenderWindow& window);
	void drawCircles();
};