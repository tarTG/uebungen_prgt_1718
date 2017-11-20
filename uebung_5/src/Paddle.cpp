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

#include "Paddle.h"
#include "EventTypes.h"

Paddle::Paddle(sf::Vector2f dir_, sf::Vector2f position,sf::Vector2f size )
 : dir{dir_}
{
    shape.setPosition(position);
    shape.setSize(size);
}

void Paddle::update() 
{
    shape.setPosition(shape.getPosition() + dir);
}

void Paddle::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

void Paddle::catchEvent(EventType e) 
{
    switch(e)
    {
        //handle all Paddle up cases
        case EventType::PADDLE_ONE_UP:
        case EventType::PADDLE_TWO_UP:
            dir = sf::Vector2f(0.0,-0.01);
            break;            
        //handle all Paddle down cases
        case EventType::PADDLE_ONE_DOWN:
        case EventType::PADDLE_TWO_DOWN:
            dir = sf::Vector2f(0.0,0.01);
            break;
        default:
            break;
    }
}

const sf::Vector2f& Paddle::getPosition() const {
    return shape.getPosition();
}

const sf::Vector2f& Paddle::getSize() const {
    return shape.getSize();
}
