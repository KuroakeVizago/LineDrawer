#pragma once
#include "Utilities/SFMLDrawer.hpp"
#include <SFML/System/Vector2.hpp>
#include "Math.hpp"
#include <SFML/Graphics.hpp>

inline sf::Vector2f QuadraticBezierCurve(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, float t)
{
    // Quadratic Bézier formula: B(t) = (1-t)^2 * a + 2 * (1-t) * t * b + t^2 * c
    float u = 1 - t;
    float tt = t * t;
    float uu = u * u;

    sf::Vector2f point = (uu * a) + (2 * u * t * b) + (tt * c);
    return point;
}

inline sf::Vector2f CubicBezierCurve(const sf::Vector2f& a, const sf::Vector2f&b, const sf::Vector2f& c, const sf::Vector2f& d, float t)
{
    sf::Vector2f level1_lerp1 =  Lerp(a, b, t);
    sf::Vector2f level1_lerp2 =  Lerp(b, c, t);
    sf::Vector2f level1_lerp3 =  Lerp(c, d, t);

    sf::Vector2f level2_lerp1 =  Lerp(level1_lerp1, level1_lerp2, t);
    sf::Vector2f level2_lerp2 =  Lerp(level1_lerp2, level1_lerp3, t);

    sf::Vector2f level3_lerp1 = Lerp(level2_lerp1, level2_lerp2, t);
    return level3_lerp1;
}

inline sf::Vector2f VisualizedCubicBezierCurve(
    sf::RenderWindow& window, 
    const sf::Vector2f& a,
    const sf::Vector2f& b,
    const sf::Vector2f& c,
    const sf::Vector2f& d,
    float t)
{
    drawPoint(window, a, 15, sf::Color::Blue);
    drawPoint(window, b, 15, sf::Color::Blue);
    drawPoint(window, c, 15, sf::Color::Blue);
    drawPoint(window, d, 15, sf::Color::Blue);

    drawLine(window, a, b, sf::Color::Blue, 5);
    drawLine(window, b, c, sf::Color::Blue, 5);
    drawLine(window, c, d, sf::Color::Blue, 5);
    
    sf::Vector2f level1_lerp1 = Lerp(a, b, t);
    sf::Vector2f level1_lerp2 = Lerp(b, c, t);
    sf::Vector2f level1_lerp3 = Lerp(c, d, t);

    drawPoint(window, level1_lerp1, 15, sf::Color::Green);
    drawPoint(window, level1_lerp2, 15, sf::Color::Green);
    drawPoint(window, level1_lerp3, 15, sf::Color::Green);
    
    drawLine(window, level1_lerp1, level1_lerp2, sf::Color::Green, 5);
    drawLine(window, level1_lerp2, level1_lerp3, sf::Color::Green, 5);

    sf::Vector2f level2_lerp1 = Lerp(level1_lerp1, level1_lerp2, t);
    sf::Vector2f level2_lerp2 = Lerp(level1_lerp2, level1_lerp3, t);
    
    drawPoint(window, level2_lerp1, 15, sf::Color::Yellow);
    drawPoint(window, level2_lerp2, 15, sf::Color::Yellow);
    
    drawLine(window, level2_lerp1, level2_lerp2, sf::Color::Yellow, 5);
    
    sf::Vector2f level3_lerp1 = Lerp(level2_lerp1, level2_lerp2, t);

    drawPoint(window, level3_lerp1, 15, sf::Color::Red);
    
    return level3_lerp1;
}
