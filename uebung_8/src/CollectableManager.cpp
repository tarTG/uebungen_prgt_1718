/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CollectableManager.cpp
 * Author: ro-lip
 * 
 * Created on 8. Dezember 2017, 11:23
 */

#include "CollectableManager.h"
#include "Collision.h"
#include <iostream>
#include <algorithm>

CollectableManager::CollectableManager() {
    t =  std::chrono::seconds(RNG::getInstance().getTimeValue()) + std::chrono::steady_clock::now();
}

std::vector<EventType> CollectableManager::checkCollisions(const Ball& b)
{
    auto ret = std::vector<EventType>();
    for(auto& d : coll)
    {
        if(Collision::intersect(b,*d))
        {
            d->valid = false;
            if(b.dir.x > 0.0)
            {
                ret.push_back(EventType::PADDLE_ONE_COLLECTABLE);
            }
            else
            {
                ret.push_back(EventType::PADDLE_TWO_COLLECTABLE);
            }
        }
    }
    return ret;

}

void CollectableManager::draw(sf::RenderWindow& window) const {
    for(auto& d : coll)
    {
        d->draw(window);
    }
}


void CollectableManager::update() {
    if(t < std::chrono::steady_clock::now())
    {
        auto c = std::make_shared<Collectable>(RNG::getInstance().getwinPosition());
        coll.push_back(std::move(c));

        
        t = std::chrono::seconds(RNG::getInstance().getTimeValue()) 
            + std::chrono::steady_clock::now();
    }
    

    auto itr = std::stable_partition(coll.begin(),coll.end(),[](auto& p){return p->valid;});
   std::vector<std::shared_ptr<Collectable>>(coll.begin(),itr).swap(coll);
    
}
