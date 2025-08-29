//
// Created by Nathan on 23/08/2025.
//

#ifndef TESTSFML_DATASERIALIZER_H
#define TESTSFML_DATASERIALIZER_H
#include <SFML/Graphics.hpp>
#include <string>

class DataSerializer
{
public :
    static std::string MatrixToString(const float* matrix);
    static std::string TransformToString(const sf::Transform& transform);
};


#endif //TESTSFML_DATASERIALIZER_H