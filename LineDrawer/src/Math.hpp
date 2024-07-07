#pragma once
#include <SFML/System/Vector2.hpp>

inline float Lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

inline sf::Vector2f Lerp(const sf::Vector2f& a, const sf::Vector2f& b, float t)
{
    return {
        Lerp(a.x, b.x, t),
        Lerp(a.y, b.y, t)
    };
}