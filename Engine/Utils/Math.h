//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_MATH_H
#define TESTSFML_MATH_H
#include <SFML/System/Vector2.hpp>
using sf::Vector2f;

class Math
{
    public:
        [[nodiscard]] static float Damp(const float& a,const float& b,const float& lambda,const float& dt);
        [[nodiscard]] static Vector2f Damp(const Vector2f& a,const Vector2f& b,const float& lambda,const float& dt);

};


#endif //TESTSFML_MATH_H