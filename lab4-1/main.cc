#include "./main.h"

const int MAX_WIDTH = 1200;
const int MAX_HEIGHT = 900;

struct Vertex {
    float x;
    float y;
};

float get_num (string message, int min, int max) {
    string line;
    float number;
    cout << message;
    while (true) {
        getline(cin, line);
        stringstream ss(line);
        if (ss >> number) {
            if (ss.eof()) {
                if (number <= min || number >= max) {
                    cout << "ERROR: a number must be from " << min << " to " << max << ": ";
                    continue;
                }
                // Success
                break;
            }
        }
        cout << "ERROR: a number (float) must be entered: ";
    }
    return number;
}

sf::ConvexShape draw_parallelogram(float x, float y, float edgeA, float edgeB, float angle) {
    Vertex a;
    Vertex b;
    Vertex c;
    Vertex d;

    a.x = 0;
    a.y = 0;

    b.x = edgeA;
    b.y = a.y;

    c.x = edgeA + cos(angle * M_PI / 180) * edgeB;
    c.y = sin(angle * M_PI / 180) * edgeB;

    d.x = c.x - edgeA;
    d.y = c.y;

    sf::ConvexShape parallelogram;

    parallelogram.setPointCount(4);
    parallelogram.setPoint(0, sf::Vector2f(a.x, a.y));
    parallelogram.setPoint(1, sf::Vector2f(b.x, b.y));
    parallelogram.setPoint(2, sf::Vector2f(c.x, c.y));
    parallelogram.setPoint(3, sf::Vector2f(d.x, d.y));

    // Move close to the center
    parallelogram.setPosition(x, y);
    //parallelogram.setScale(30, 30);
    // parallelogram.rotate(90);
    parallelogram.setFillColor(sf::Color(220, 220, 220));
    parallelogram.setOutlineThickness(-4.f);
    parallelogram.setOutlineColor(sf::Color::Black);

    return parallelogram;
}

int main() {

    float edgeA;
    float edgeB;
    float angle;
    float x;
    float y;

    stringstream ss;

    ss << "Input edge A length (from 0 to " << MAX_WIDTH/2 << "): ";
    edgeA = get_num(ss.str(), 0, MAX_WIDTH/2);
    ss.str("");

    ss << "Input edge B length (from 0 to " << MAX_HEIGHT/2 << "): ";
    edgeB = get_num(ss.str(), 0, MAX_HEIGHT/2);
    ss.str("");

    angle = get_num("Input angle (from 0 to 180): ", 0, 180);

    ss << "Input X position of the shape (from " << edgeB << " to " << MAX_WIDTH - edgeA - edgeB << "): ";
    x = get_num(ss.str(), edgeB, MAX_WIDTH - edgeA - edgeB);
    ss.str("");

    ss << "Input Y position of the shape (from 0 to " << MAX_HEIGHT - edgeB << "): ";
    y = get_num(ss.str(), 0, MAX_HEIGHT - edgeB);
    ss.str("");

    sf::ContextSettings settings;
    settings.antialiasingLevel = 16;
    sf::RenderWindow window(sf::VideoMode(MAX_WIDTH, MAX_HEIGHT), "Lab1", sf::Style::Default, settings);

    sf::ConvexShape parallelogram = draw_parallelogram(x, y, edgeA, edgeB, angle);

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