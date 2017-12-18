/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GUI.cpp
 * Author: ro-lip
 * 
 * Created on 30. November 2017, 13:13
 */




#include "GUI.h"
#include <iostream>

GUI::GUI(const sf::Vector2f& position1,const sf::Vector2f& position2) 
: iPoints1(0), iPoints2(0)
{
    
    if(!f.loadFromFile("/usr/share/fonts/TTF/DejaVuSans-ExtraLight.ttf"))
    {
        throw std::invalid_argument("Font not found");
    }    

    tPoints1.setPosition(position1);
    tPoints1.setFillColor(sf::Color::Yellow);
    tPoints1.setCharacterSize(60);

    tPoints1.setFont(f);
    
    tPoints2.setPosition(position2);
    tPoints2.setFillColor(sf::Color::Yellow);
    tPoints2.setCharacterSize(60);
    tPoints2.setFont(f);
}

void GUI::catchEvent(EventType e) {
  switch(e)
  {    
    case EventType::BALL_Y_BORDER_COLLISION_LEFT:
        ++iPoints2;
        break;
    case EventType::BALL_Y_BORDER_COLLISION_RIGHT:
        ++iPoints1;
        break; 
      default:
          break;
  }

}

void GUI::draw( sf::RenderWindow& w) {
    tPoints1.setString(std::to_string(iPoints1));
    tPoints2.setString(std::to_string(iPoints2));    
    w.draw(tPoints1);
    w.draw(tPoints2);
}
