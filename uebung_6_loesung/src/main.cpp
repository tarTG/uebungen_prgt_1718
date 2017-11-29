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
#include <list>

#include "Paddle.h"
#include "Ball.h"
#include "Observed.h"
#include "Collision.h"


const float paddleSizeY = 70.f;
const float paddleSizeX = 10.f;
const float paddleWallDistance = 20.f;
const float BallSize = 10.f;


int main()
{
    
    //here starts the SFML example 
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    
    std::vector<std::unique_ptr<IGameObject>> objects; //here we save all objects

    objects.push_back(std::make_unique<Paddle>(
                        sf::Vector2f(0.0f,0.0f),
                        sf::Vector2f(paddleWallDistance,window.getSize().y / 2.f - paddleSizeY/2.f),
                        sf::Vector2f(paddleSizeX,paddleSizeY)));
    
    objects.push_back(std::make_unique<Paddle>(
                        sf::Vector2f(0.0f,0.0f),
                        sf::Vector2f(window.getSize().x -paddleWallDistance,window.getSize().y / 2.f - paddleSizeY/2.f), 
                        sf::Vector2f(paddleSizeX,paddleSizeY)));
    
    objects.push_back(std::make_unique<Ball>(
                        sf::Vector2f(0.04f,0.04f),
                        sf::Vector2f(window.getSize().x / 2,window.getSize().y / 2), 
                        BallSize));
    
    auto borders = std::vector<Border>({Border(0,Border::Orientation::X),
                                        Border(window.getSize().y,Border::Orientation::X),
                                        Border(0,Border::Orientation::Y),
                                         Border(window.getSize().x,Border::Orientation::Y)   });
    
    auto observer = Observed(); // Create Observed
    
    //add events
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(0).get()),EventType::PADDLE_ONE_UP);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(0).get()),EventType::PADDLE_ONE_DOWN);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(0).get()),EventType::PADDLE_ONE_BORDER_COLLISION);
    
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(1).get()),EventType::PADDLE_TWO_UP);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(1).get()),EventType::PADDLE_TWO_DOWN);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(1).get()),EventType::PADDLE_TWO_BORDER_COLLISION);

    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::PADDLE_ONE_BALL_COLLISION);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::PADDLE_TWO_BALL_COLLISION);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::BALL_X_BORDER_COLLISION);
    observer.addObserver(dynamic_cast<IObserver*>(objects.at(2).get()),EventType::BALL_Y_BORDER_COLLISION);
    
    
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
                if(event.key.code == sf::Keyboard::W) // when up-Key is pressed
                {
                    //cast IGameObject to paddle and change direction
                    observer.sendEvent(EventType::PADDLE_ONE_UP);
                }
                else if(event.key.code == sf::Keyboard::S)
                {
                    observer.sendEvent(EventType::PADDLE_ONE_DOWN);
                }            
                if(event.key.code == sf::Keyboard::Up) // when up-Key is pressed
                {
                    //cast IGameObject to paddle and change direction
                    observer.sendEvent(EventType::PADDLE_TWO_UP);
                }
                else if(event.key.code == sf::Keyboard::Down)
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
       
        
        for(auto& i : borders)
        {
            if(Collision::intersect(*dynamic_cast<Paddle*>(objects.at(0).get()),i))
            {
                observer.sendEvent(EventType::PADDLE_ONE_BORDER_COLLISION);
            }
        }        
        
        for(auto& i : borders)
        {
            if(Collision::intersect(*dynamic_cast<Paddle*>(objects.at(1).get()),i))
            {
                observer.sendEvent(EventType::PADDLE_TWO_BORDER_COLLISION);                
            }
        }        
        
        for(auto& i : borders)
        {
            if(Collision::intersect(*dynamic_cast<Ball*>(objects.at(2).get()),i))
            {
                if(i.GetOriantition() == Border::Orientation::X)
                {
                    observer.sendEvent(EventType::BALL_X_BORDER_COLLISION); 
                }
                if(i.GetOriantition() == Border::Orientation::Y)
                {
                    observer.sendEvent(EventType::BALL_Y_BORDER_COLLISION); 
                }
            }
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
