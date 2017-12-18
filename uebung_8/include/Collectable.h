/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collectable.h
 * Author: ro-lip
 *
 * Created on 7. Dezember 2017, 15:58
 */

#ifndef COLLECTABLE_H
#define COLLECTABLE_H

#include "IGameObject.h"
#include "IObserver.h"

class Collectable {
    
public:
    Collectable(const sf::Vector2f& pos);
    bool valid = true;

    void draw(sf::RenderWindow& window) const;

    sf::Vector2f getPosition() const;
    float getSize() const;

private:
    sf::CircleShape shape;
    const float CollectableRadius = 14.f;

};

#endif /* COLLECTABLE_H */

