//
// Created by Nathan on 21/09/2025.
//

#ifndef TESTSFML_AABB_H
#define TESTSFML_AABB_H
#include <SFML/System/Vector2.hpp>

#include "Collider.h"

struct AABB : Collider
{
    sf::Vector2f center;
    sf::Vector2f halfSize;
};

#endif //TESTSFML_AABB_H