#include <SFML/Graphics.hpp>
#include <iostream>

// Function to plot points for the circle
inline void plotPoints(sf::RenderWindow& window, int xc, int yc, int x, int y) {
    sf::Vertex points[] = {
        sf::Vertex(sf::Vector2f(xc + x, yc + y), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc - x, yc + y), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc + x, yc - y), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc - x, yc - y), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc + y, yc + x), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc - y, yc + x), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc + y, yc - x), sf::Color::White),
        sf::Vertex(sf::Vector2f(xc - y, yc - x), sf::Color::White)
    };

    for (const auto& point : points) {
        window.draw(&point, 1, sf::Points);
    }
}

// Function to draw a circle using Bresenham's algorithm
inline void bresenhamCircle(sf::RenderWindow& window, int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 3 - 2 * r;
    plotPoints(window, xc, yc, x, y);
    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        plotPoints(window, xc, yc, x, y);
    }
}

   
