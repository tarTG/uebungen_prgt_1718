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
    
    float DeltaX = b.getPosition().x - std::max(p.getPosition().x, std::min(b.getPosition().x, p.getPosition().x + p.getSize().x));
    float DeltaY = b.getPosition().y - std::max(p.getPosition().y, std::min(b.getPosition().y, p.getPosition().y + p.getSize().y));
    return (DeltaX * DeltaX + DeltaY * DeltaY) < (b.getSize() * b.getSize());
}

bool Collision::intersect(const Paddle& p, const Border& boarder)
{
    if(boarder.GetOriantition() == Border::Orientation::X)
    {
        if(p.getPosition().y < boarder.GetPos() && (p.getPosition().y + p.getSize().y) > boarder.GetPos())
            return true;
    }
    return false;       
}

bool Collision::intersect(const Ball& p, const Border& boarder)
{
    if(boarder.GetOriantition() == Border::Orientation::X)
    {
        if(p.getPosition().y < boarder.GetPos() && (p.getPosition().y + p.getSize() ) > boarder.GetPos())
               return true;   
    }
    else
    {
        if(p.getPosition().x < boarder.GetPos() && (p.getPosition().x + p.getSize() ) > boarder.GetPos())
            return true;     
    }    
    return false;  
}

