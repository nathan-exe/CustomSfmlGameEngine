//
// Created by Nathan on 26/08/2025.
//

#include "Math.h"

#include <cmath>

float Math::Damp(const float& a,const float& b,const float& lambda,const float& dt)
{
        return std::lerp(a, b, 1 - exp(-lambda * dt));
}

Vector2f Math::Damp(const Vector2f& a,const Vector2f& b,const float& lambda,const float& dt)
{
        return {Damp(a.x, b.x, lambda, dt),Damp(a.y,b.y,lambda,dt)};
}
