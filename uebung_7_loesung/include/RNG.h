/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RNG.h
 * Author: ro-lip
 *
 * Created on 30. November 2017, 15:27
 */

#ifndef RNG_H
#define RNG_H

#include <random>

class RNG {
    
private:
    RNG();
    std::mt19937 r;
     std::uniform_real_distribution<float> dist;
public:
    static RNG& getInstance();

    //generate a float value between -1 and 1
    float getDirValue();
 

};

#endif /* RNG_H */

