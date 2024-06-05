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

inline void drawCircle(int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    // Plot the initial point in each octant
    std::cout << "(" << x << ", " << y << ")" << std::endl;
    std::cout << "(" << -x << ", " << y << ")" << std::endl;
    std::cout << "(" << x << ", " << -y << ")" << std::endl;
    std::cout << "(" << -x << ", " << -y << ")" << std::endl;
    std::cout << "(" << y << ", " << x << ")" << std::endl;
    std::cout << "(" << -y << ", " << x << ")" << std::endl;
    std::cout << "(" << y << ", " << -x << ")" << std::endl;
    std::cout << "(" << -y << ", " << -x << ")" << std::endl;

    while (y > x) {
        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;

        // Plot points in each octant
        std::cout << "(" << x << ", " << y << ")" << std::endl;
        std::cout << "(" << -x << ", " << y << ")" << std::endl;
        std::cout << "(" << x << ", " << -y << ")" << std::endl;
        std::cout << "(" << -x << ", " << -y << ")" << std::endl;
        std::cout << "(" << y << ", " << x << ")" << std::endl;
        std::cout << "(" << -y << ", " << x << ")" << std::endl;
        std::cout << "(" << y << ", " << -x << ")" << std::endl;
        std::cout << "(" << -y << ", " << -x << ")" << std::endl;
    }
}
