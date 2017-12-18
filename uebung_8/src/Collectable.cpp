/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collectable.cpp
 * Author: ro-lip
 * 
 * Created on 7. Dezember 2017, 15:58
 */

#include "Collectable.h"

Collectable::Collectable(const sf::Vector2f& pos) 
{
    shape.setRadius(CollectableRadius);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos);

}

void Collectable::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}


sf::Vector2f Collectable::getPosition() const {
    return shape.getPosition();
}

float Collectable::getSize() const {
    return shape.getRadius();
}
