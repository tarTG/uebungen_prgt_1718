/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GUI.h
 * Author: ro-lip
 *
 * Created on 30. November 2017, 13:13
 */

#ifndef GUI_H
#define GUI_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "IObserver.h"


class GUI : public  IObserver {
public:
    GUI(const sf::Vector2f& position1,const sf::Vector2f& position2);
    void catchEvent(EventType e);
    void draw(sf::RenderWindow& w);
private:
    sf::Text tPoints1;
    sf::Text tPoints2;
    uint32_t iPoints1;
    uint32_t iPoints2;
    sf::Font f;
};

#endif /* GUI_H */

