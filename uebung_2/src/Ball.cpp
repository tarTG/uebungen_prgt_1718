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
 : dir{dir_}
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
