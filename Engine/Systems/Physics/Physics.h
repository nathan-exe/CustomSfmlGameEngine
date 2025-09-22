//
// Created by Nathan on 21/09/2025.
//

#ifndef TESTSFML_PHYSICS_H
#define TESTSFML_PHYSICS_H
#include "Shapes/Collider.h"

using sf::Vector2f;

static class Physics
{
    [[nodiscard]] static std::optional<HitResult> RayCast(const Vector2f& origin,const Vector2f& direction, const Collider& collider);
    [[nodiscard]] static std::optional<HitResult> CircleCast(const Vector2f& origin,const Vector2f& direction,const float& radius,const Collider& collider);
};


#endif //TESTSFML_PHYSICS_H