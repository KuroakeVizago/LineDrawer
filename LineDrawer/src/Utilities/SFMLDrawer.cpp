#include <SFML/Graphics.hpp>

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

void drawLine(sf::RenderWindow& window, const sf::Vector2f& start, const sf::Vector2f& end, const sf::Color& color, float thickness)
{
    sf::Vertex line[] =
    {
        sf::Vertex(start, color),
        sf::Vertex(end, color)
    };

    // Create a rectangle to represent the thickness
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(thickness, thickness));
    rectangle.setFillColor(color);
    rectangle.setPosition(start);

    // Calculate the angle of the line
    float dx = end.x - start.x;
    float dy = end.y - start.y;
    float angle = atan2(dy, dx) * 180 / 3.14159265f;
    rectangle.setRotation(angle);

    // Set the length of the rectangle to be the distance between the points
    float length = sqrt(dx * dx + dy * dy);
    rectangle.setSize(sf::Vector2f(length, thickness));

    // Draw the rectangle
    window.draw(rectangle);
}

void drawPoint(sf::RenderWindow& window, const sf::Vector2f& point, const float& radius, const sf::Color& color)
{
    sf::CircleShape circle(radius);
    circle.setPosition(point - sf::Vector2f(circle.getRadius(), circle.getRadius()));
    circle.setFillColor(color);
    window.draw(circle);
}
