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
#include <memory>
#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "Observed.h"
#include "Collision.h"



int main()
{
    
    //here starts the SFML example 
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    std::vector<std::unique_ptr<IGameObject>> objects; //here we save all objects

    objects.push_back(std::make_unique<Paddle>(sf::Vector2f(0.0f,0.0f),
                        sf::Vector2f(50.f,100.f), sf::Vector2f(10,70)));
    objects.push_back(std::make_unique<Paddle>(sf::Vector2f(0.0f,0.0f),
                        sf::Vector2f(600.f,100.f), sf::Vector2f(10,70)));
    
    objects.push_back(std::make_unique<Ball>(sf::Vector2f(0.01f,0.00f),
                    sf::Vector2f(200.f,100.f),  5));
    
    auto observer = Observed(); // Create Observed
    
    //add events
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(0).get()),EventType::PADDLE_ONE_UP);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(0).get()),EventType::PADDLE_ONE_DOWN);

    observer.addObserver(dynamic_cast<IObserver*>(objects.at(1).get()),EventType::PADDLE_TWO_UP);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(1).get()),EventType::PADDLE_TWO_DOWN);

    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::PADDLE_ONE_BALL_COLLISION);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::PADDLE_TWO_BALL_COLLISION);
    
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
            if(event.type == sf::Event::KeyPressed) //get Key event
            {
                if(event.key.code == sf::Keyboard::Up) // when up-Key is pressed
                {
                    //cast IGameObject to paddle and change direction
                    observer.sendEvent(EventType::PADDLE_ONE_UP);
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    observer.sendEvent(EventType::PADDLE_ONE_DOWN);
                }            
                if(event.key.code == sf::Keyboard::W) // when up-Key is pressed
                {
                    //cast IGameObject to paddle and change direction
                    observer.sendEvent(EventType::PADDLE_TWO_UP);
                }
                else if(event.key.code == sf::Keyboard::S)
                {
                    observer.sendEvent(EventType::PADDLE_TWO_DOWN);
                }                    
            }
        }
        if(Collision::intersect(*dynamic_cast<Ball*>(objects.at(2).get()),*dynamic_cast<Paddle*>(objects.at(0).get())))
        {
            observer.sendEvent(EventType::PADDLE_TWO_BALL_COLLISION);
        }
        if(Collision::intersect(*dynamic_cast<Ball*>(objects.at(2).get()),*dynamic_cast<Paddle*>(objects.at(1).get())))
        {
            observer.sendEvent(EventType::PADDLE_ONE_BALL_COLLISION);
        }
        
        
        observer.update();
        for(auto& o : objects) //update all objects
        {
            o->update();
        }
        
        window.clear(sf::Color(0, 0, 0));
        
        for(auto& o : objects) //draw all objects
        {
            o->draw(window);
        }
        
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
