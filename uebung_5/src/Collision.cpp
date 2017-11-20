/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collision.cpp
 * Author: ro-lip
 * 
 * Created on 17. November 2017, 12:55
 */

#include "Collision.h"


bool Collision::intersect(const Ball& b, const Paddle& p) {
    
    float DeltaX = b.getPostion().x - std::max(p.getPosition().x, std::min(b.getPostion().x, p.getPosition().x + p.getSize().x));
    float DeltaY = b.getPostion().y - std::max(p.getPosition().y, std::min(b.getPostion().y, p.getPosition().y + p.getSize().y));
    return (DeltaX * DeltaX + DeltaY * DeltaY) < (b.getSize() * b.getSize());
}
