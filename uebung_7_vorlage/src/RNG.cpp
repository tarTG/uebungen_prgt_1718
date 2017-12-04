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

#include "RNG.h"

RNG* RNG::instanz = 0;  

RNG* RNG::getInstance() {
  if( instanz == 0 )
    instanz = new RNG();
  return instanz;
}

float RNG::getDirValue() {
 return -1.f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(2.f)));
}



RNG::RNG() {
    srand(time_t(NULL));
}

