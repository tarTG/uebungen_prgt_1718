/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RNG.cpp
 * Author: ro-lip
 * 
 * Created on 30. November 2017, 15:27
 */

#include <cstdlib>
#include <SFML/System/Vector2.hpp>

#include "RNG.h"


RNG& RNG::getInstance() {
    static RNG instanz;
    return instanz;
}

float RNG::getDirValue() {
 return dist(r);
}


uint32_t RNG::getTimeValue() {
 return CollTime(r);
}

sf::Vector2f RNG::getwinPosition() {
 return sf::Vector2f(winPositionX(r),winPositionY(r));
}


RNG::RNG() {
    r = std::mt19937(std::random_device()());
    dist = std::uniform_real_distribution<float>(-1,1);
    CollTime = std::uniform_int_distribution<uint32_t>(1,2);
    winPositionX = std::uniform_real_distribution<float>(0,800);
    winPositionY = std::uniform_real_distribution<float>(0,600);
}

