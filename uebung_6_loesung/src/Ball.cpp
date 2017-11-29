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


#include "Ball.h"

Ball::Ball(sf::Vector2f dir_, sf::Vector2f position,float size )
 : dir{dir_}, origin{position}
{
    shape.setPosition(position);
    shape.setRadius(size);
}

void Ball::update() 
{
    shape.setPosition(shape.getPosition() + dir);
}

void Ball::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

const sf::Vector2f Ball::getPosition() const {
    return shape.getPosition();
}

const float Ball::getSize() const {
    return shape.getRadius();
}

void Ball::catchEvent(EventType e) {
    switch(e)
    {
        case EventType::PADDLE_ONE_BALL_COLLISION:
             dir = sf::Vector2f(dir.y, -dir.x);
             break;
        case EventType::PADDLE_TWO_BALL_COLLISION:
            dir = sf::Vector2f(dir.y, -dir.x);
            break;
        case EventType::BALL_X_BORDER_COLLISION:
            dir = sf::Vector2f(dir.y, -dir.x);
            break;
        case EventType::BALL_Y_BORDER_COLLISION:
            shape.setPosition(origin);
            break;
        default:
            break;
    }
}
