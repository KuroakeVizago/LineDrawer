#pragma once
#include "Utilities/SFMLDrawer.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>

// Function to draw a line using DDA algorithm
inline void drawLineDDA(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = float(dx) / steps;
    float yIncrement = float(dy) / steps;
    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; ++i) {
        std::cout << "(" << round(x) << ", " << round(y) << ")" << std::endl;
        x += xIncrement;
        y += yIncrement;
    }
}

// Function to draw a line using Bresenham's algorithm
inline void drawLineBressenham(int x0, int y0, int x1, int y1) {
    int distanceX = abs(x1 - x0);
    int distanceY = abs(y1 - y0);
    int stepX = (x0 < x1) ? 1 : -1;
    int stepY = (y0 < y1) ? 1 : -1;

    //Error Pixel
    int err = distanceX - distanceY;

    while (x0 != x1 || y0 != y1) {
        std::cout << "(" << x0 << ", " << y0 << ")" << std::endl;
        //Error Pixel determine where the y or x will change (based on which one is smaller from the distance X or Y)
        int err2 = 2 * err;
        
        if (err2 > -distanceY) {
            err -= distanceY;
            x0 += stepX;
        }
        
        if (err2 < distanceX) {
            err += distanceX;
            y0 += stepY;
        }
    }
    std::cout << "(" << x1 << ", " << y1 << ")" << std::endl;  // Include the endpoint
}

// Function to draw a line using Bresenham's algorithm
inline void drawLineBressenham(
    sf::RenderWindow& window,
    const sf::Vector2f& a,
    const sf::Vector2f& b, const sf::Color& color, const float& thickness) {

    sf::Vector2f currentPosition(a);
    drawPoint(window, currentPosition, thickness * 2,sf::Color::Red);
    
    int distanceX = abs(b.x - a.x);
    int distanceY = abs(b.y - a.y);
    int stepX = (a.x < b.x) ? 1 : -1;
    int stepY = (a.y < b.y) ? 1 : -1;

    //Error Pixel
    int err = distanceX - distanceY;

    while (currentPosition.x != b.x || currentPosition.y != b.y) {
        //Error Pixel determine where the y or x will change (based on which one is smaller from the distance X or Y)
        int err2 = 2 * err;
        
        if (err2 > -distanceY) {
            err -= distanceY;
            currentPosition.x += stepX;
        }
        
        if (err2 < distanceX) {
            err += distanceX;
            currentPosition.y += stepY;
        }

        drawPoint(window, currentPosition, thickness, color);

    }
    
    drawPoint(window, b, 5,sf::Color::Red);
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
