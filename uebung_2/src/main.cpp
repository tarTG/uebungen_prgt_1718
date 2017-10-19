//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.

/* 
 * File:   main.cpp
 * Author: Tobias Gerteis
 *
 * Created on 19. Oktober 2017, 13:07
 */

#include <iostream>
#include <inttypes.h>
#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"



int main()
{
    
    //here starts the SFML example 
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    Paddle leftPaddle = Paddle(sf::Vector2f(0.01f,0.01f),sf::Vector2f(100.f,100.f),
                                sf::Vector2f(5,10));

    Ball ball = Ball(sf::Vector2f(0.01f,0.001f),sf::Vector2f(100.f,100.f),
                                5);
    
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        leftPaddle.update();
        ball.update();
        
        window.clear(sf::Color(0, 0, 0));
        
        leftPaddle.draw(window);
        ball.draw(window);
        
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
