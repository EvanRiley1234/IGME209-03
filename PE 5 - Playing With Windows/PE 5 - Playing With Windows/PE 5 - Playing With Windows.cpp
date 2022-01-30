// PE 5 - Playing With Windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define SFML_STATIC
#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        // draw everything here...

        //circle shape
        sf::CircleShape circle(50.f);
        circle.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle);

        //rectangle shape
        sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
        rectangle.setFillColor(sf::Color(250, 250, 250));
        rectangle.setPosition(300.f, 300.f);
        window.draw(rectangle);

        //triangle shape
        sf::CircleShape triangle(80.f, 3);
        triangle.setFillColor(sf::Color(250, 0, 250));
        triangle.setPosition(500.f, 100.f);
        window.draw(triangle);

        //octagon shape
        sf::CircleShape octagon(80.f, 8);
        octagon.setFillColor(sf::Color(250, 250, 0));
        octagon.setPosition(100.f, 300.f);
        window.draw(octagon);

        // end the current frame
        window.display();
    }

    return 0;

}