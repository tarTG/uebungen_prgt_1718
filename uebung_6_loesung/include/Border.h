/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BorderX.h
 * Author: ro-lip
 *
 * Created on 24. November 2017, 10:19
 */

#ifndef BORDERX_H
#define BORDERX_H

#include <SFML/System/Vector2.hpp>


class Border {
public:
    
    enum class Orientation
    {
        X,
        Y
    };
    
    Border(const float Pos,const Orientation& o);

    float GetPos() const;
    Orientation GetOriantition() const;
    
    
    
private:
    float pos;
    Orientation oriantition;
};

#endif /* BORDERX_H */

