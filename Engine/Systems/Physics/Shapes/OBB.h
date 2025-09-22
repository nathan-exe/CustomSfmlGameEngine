//
// Created by Nathan on 21/09/2025.
//

#ifndef TESTSFML_ORIENTEDBOUNDINGBOX_H
#define TESTSFML_ORIENTEDBOUNDINGBOX_H
#include <SFML/System/Vector2.hpp>

///oriented bounding box
class OBB : Shape
{
    sf::Vector2f center;
    sf::Vector2f halfSize;
    sf::Angle angle;

    public:

};

#endif //TESTSFML_ORIENTEDBOUNDINGBOX_H