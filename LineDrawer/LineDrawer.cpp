#include <iostream>
#include<SFML/Graphics.hpp>

// Function to plot points for the circle
void plotPoints(sf::RenderWindow& window, int xc, int yc, int x, int y) {
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
void bresenhamCircle(sf::RenderWindow& window, int xc, int yc, int r) {
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

#include "src/DrawAlgorithm.hpp"


void SFML_Visual_Drawer()
{
    int xc = 250; // Koordinat x pusat lingkaran
    int yc = 250; // Koordinat y pusat lingkaran
    int radius = 100; // Jari-jari lingkaran

    sf::RenderWindow window(sf::VideoMode(500, 500), "Bresenham Circle");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        bresenhamCircle(window, xc, yc, radius);
        window.display();
    }
}

int main()
{
    //std::cout << "DDA:" << std::endl;
    //drawLineDDA(0,0,5,10);
    //std::cout << "Bressenham:" << std::endl;
    //drawLineBressenham(0, 0, 5, 10);
    //std::cout << "Circle:" << std::endl;

    SFML_Visual_Drawer();
}
