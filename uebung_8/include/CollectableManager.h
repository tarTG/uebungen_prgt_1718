/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectableManager.h
 * Author: ro-lip
 *
 * Created on 8. Dezember 2017, 11:23
 */

#ifndef COLLECTABLEMANAGER_H
#define COLLECTABLEMANAGER_H

#include <chrono>
#include <random>
#include <memory>
#include "Ball.h"
#include "Collectable.h"

class CollectableManager : IGameObject
{
    

public:
        CollectableManager();
    
    std::vector<EventType> checkCollisions(const Ball& b);
    
    void update() override;

    void draw(sf::RenderWindow& window) const override;

    
private:

    std::vector<std::shared_ptr<Collectable>> coll;
    std::chrono::steady_clock::time_point t;


};

#endif /* COLLECTABLEMANAGER_H */

