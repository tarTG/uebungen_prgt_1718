/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Collision.h
 * Author: ro-lip
 *
 * Created on 17. November 2017, 12:55
 */

#ifndef COLLISION_H
#define COLLISION_H

#include "Ball.h"
#include "Paddle.h"

class Collision {
public:
    static bool intersect(const Ball& b, const Paddle& p);

};

#endif /* COLLISION_H */

