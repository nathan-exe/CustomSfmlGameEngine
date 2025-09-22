//
// Created by Megaport on 21/09/2025.
//

#ifndef TESTSFML_HITRESULT_H
#define TESTSFML_HITRESULT_H
#include <SFML/System/Vector2.hpp>

struct HitResult
{
    sf::Vector2f point;
    sf::Vector2f normal;
    float distance;
};

#endif TESTSFML_HITRESULT_H