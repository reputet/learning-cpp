#define _USE_MATH_DEFINES

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    float sideA;
    float sideB;
    float angle;

    std::cout << "Input edge A: ";
    std::cin >> sideA;
    std::cout << "Input edge B: ";
    std::cin >> sideB;
    std::cout << "Input angle: ";
    std::cin >> angle;
    struct Point {
        float x;
        float y;
    };

    Point a;
    Point b;
    Point c;
    Point d;

    a.x = 0;
    a.y = 0;
    b.x = 0;
    b.y = sideA;
    c.x = cos((90 - angle) * M_PI / 180) * sideB;
    c.y = b.y - sin((90 - angle) * M_PI / 180) * sideB;
    d.x = c.x;
    d.y = c.y - sideA;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!", sf::Style::Default, settings);

    sf::ConvexShape parallelogram;

    parallelogram.setPointCount(4);

    parallelogram.setPoint(0, sf::Vector2f(a.x, a.y));
    parallelogram.setPoint(1, sf::Vector2f(b.x, b.y));
    parallelogram.setPoint(2, sf::Vector2f(c.x, c.y));
    parallelogram.setPoint(3, sf::Vector2f(d.x, d.y));
    parallelogram.setPosition(300, 300);
    // parallelogram.rotate(180.f);
    parallelogram.setScale(30, 30);
    // parallelogram.setFillColor(sf::Color::Green);
    // parallelogram.setFillColor(sf::Color::Black);
    parallelogram.setFillColor(sf::Color(220, 220, 220));
    parallelogram.setOutlineThickness(-1.f / 8);
    // parallelogram.setOutlineColor(sf::Color(250, 150, 100));
    parallelogram.setOutlineColor(sf::Color::Black);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(180, 180, 180));
        window.draw(parallelogram);
        window.display();
    }

    return 0;
}