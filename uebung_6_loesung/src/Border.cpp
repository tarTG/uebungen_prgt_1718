/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BorderX.cpp
 * Author: ro-lip
 * 
 * Created on 24. November 2017, 10:19
 */

#include "Border.h"

Border::Border(const float Pos,const Orientation& o) : pos(Pos), oriantition(o) {
}

Border::Orientation Border::GetOriantition() const {
    return oriantition;
}

float Border::GetPos() const {
    return pos;
}
