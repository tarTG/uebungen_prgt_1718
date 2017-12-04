/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EventTypes.h
 * Author: ro-lip
 *
 * Created on 9. November 2017, 16:07
 */

#ifndef EVENTTYPES_H
#define EVENTTYPES_H

enum class EventType
{
    PADDLE_ONE_UP,
    PADDLE_ONE_DOWN,
    PADDLE_TWO_UP,
    PADDLE_TWO_DOWN,
    PADDLE_ONE_BALL_COLLISION,
    PADDLE_TWO_BALL_COLLISION,
    PADDLE_ONE_BORDER_COLLISION,
    PADDLE_TWO_BORDER_COLLISION,
    BALL_X_BORDER_COLLISION,
    BALL_Y_BORDER_COLLISION_LEFT,
    BALL_Y_BORDER_COLLISION_RIGHT
};

#endif /* EVENTTYPES_H */

