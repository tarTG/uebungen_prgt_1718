/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Observed.h
 * Author: ro-lip
 *
 * Created on 9. November 2017, 16:15
 */

#ifndef OBSERVED_H
#define OBSERVED_H

#include <vector>
#include <unordered_map>

#include "IObserver.h"

class Observed 
{
    //List of observers
    typedef std::vector<IObserver*> ObserverList;
    typedef std::unordered_map<EventType, ObserverList> observersTable;
    //map of observers for specific event type
    observersTable m_observers;
    //list of happend events
    std::vector<EventType> events;
public:
    //Add observer to the evtHandler
    void addObserver(IObserver* observer, EventType eType);

    //save Event
    void sendEvent(EventType event);
    //update events
    void update();

};

#endif /* OBSERVED_H */

