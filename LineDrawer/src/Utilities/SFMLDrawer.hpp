#pragma once
#include <SFML/Graphics.hpp>

// Function to plot points for the circle
void plotPoints(sf::RenderWindow& window, int xc, int yc, int x, int y);

void drawLine(sf::RenderWindow& window, const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color, float thickness);

void drawPoint(sf::RenderWindow& window, const sf::Vector2f& point, const float& radius, const sf::Color& color);