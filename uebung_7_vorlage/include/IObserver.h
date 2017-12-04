/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   IObersver.h
 * Author: ro-lip
 *
 * Created on 9. November 2017, 16:08
 */

#ifndef IOBERSVER_H
#define IOBERSVER_H

#include "EventTypes.h"

class IObserver
{
public:
    virtual void catchEvent(EventType e) = 0;
};

#endif /* IOBERSVER_H */

