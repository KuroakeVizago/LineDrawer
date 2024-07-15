#include <iostream>
#include <SFML/Graphics.hpp>
#include "src/BezierCurve.hpp"
#include "src/DrawAlgorithm.hpp"

void SFML_Visual_Drawer()
{
    int xc = 250; // Koordinat x pusat lingkaran
    int yc = 500; // Koordinat y pusat lingkaran
    int radius = 100; // Jari-jari lingkaran

    // Define two points
    sf::Vector2f point1(100, 100);
    sf::Vector2f point2(500, 200);

    // Define control points
    sf::Vector2f pointA(600, 500);
    sf::Vector2f pointB(800, 200);
    sf::Vector2f pointC(1000, 700);
    sf::Vector2f pointD(1500, 400);

    sf::Vector2f pointE(200, 100);
    sf::Vector2f pointF(250, 150);
    

    // Generate points on the curve
    // Number of points on the curve
    int numPoints = 100; // Number of points on the curve
    float time = 0.0f;
    float deltaTime = 0.4f / numPoints;
    bool forward = true;
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Project Line Drawer");

    std::vector<sf::Vector2f> curvePoints;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        
        // Update the position of the point along the curve
        if (forward)
        {
            time += deltaTime;
            if (time >= 1.0f)
            {
                time = 1.0f;
                forward = false;
            }
        }
        else
        {
            time -= deltaTime;
            if (time <= 0.0f)
            {
                time = 0.0f;
                forward = true;
            }
        }
        
        drawLine(window, pointA, pointB, sf::Color::Blue, 5);
        drawLine(window, pointB, pointC, sf::Color::Blue, 5);
        drawLine(window, pointC, pointD, sf::Color::Blue, 5);

        //Calculate and Visualize Cubic Bezier Curve
        sf::Vector2f point = CubicBezierCurve(pointA, pointB, pointC, pointD, time);
        auto newPoint = VisualizedCubicBezierCurve(window, pointA, pointB, pointC, pointD, time);
        
        for (int i = 0; i < curvePoints.size(); ++i)
        {
            if (curvePoints[i] == newPoint)
            {
                curvePoints.erase(curvePoints.begin() + i);
                break; // Assuming you want to delete only the first matching point
            }
        }

        curvePoints.emplace_back(newPoint);

        for (const auto& point : curvePoints)
        {
            drawPoint(window, point, 5, sf::Color::Red);
        }
        
        drawLineBressenham(window, pointE, pointF);

        
        window.display();
    }
}

int main()
{
    std::string input;
    std::cin >> input;
    
    std::cout << "DDA:" << std::endl;
    drawLineDDA(0,0,5,10);
    std::cout << "Bressenham:" << std::endl;
    drawLineBressenham(0, 0, 5, 10);

    if (input == "Visualizer")
    {
        SFML_Visual_Drawer();   
    }
}
