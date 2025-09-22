//
// Created by Nathan on 21/09/2025.
//

#ifndef TESTSFML_CIRCLE_H
#define TESTSFML_CIRCLE_H
#include "Collider.h"
#include <SFML/System/Vector2.hpp>

///un cercle
class Circle : public Collider
{
public:
    float radius;
    sf::Vector2f center;
};

#endif //TESTSFML_CIRCLE_H