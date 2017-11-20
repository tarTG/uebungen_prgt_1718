/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observed.cpp
 * Author: ro-lip
 * 
 * Created on 9. November 2017, 16:15
 */

#include "Observed.h"

void Observed::addObserver(IObserver* observer, EventType eType) 
{
    m_observers[eType].push_back(observer);
}

void Observed::sendEvent(EventType event)
{
    events.push_back(event);
}

void Observed::update()
{
    for (auto e : events) 
    {
        for (auto& o : m_observers[e])
        {
            o->catchEvent(e);
        }
    }
    events.clear();
}
