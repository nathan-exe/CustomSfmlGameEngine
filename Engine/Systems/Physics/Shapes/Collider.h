//
// Created by Megaport on 21/09/2025.
//

#ifndef TESTSFML_SHAPE_H
#define TESTSFML_SHAPE_H
#include <optional>
#include <SFML/System/Vector2.hpp>
#include "../HitResult.h"

using sf::Vector2f;

class Ray;
class Circle;
class OBB;
class AABB;

///ahhh
class Collider
{
public:
        [[nodiscard]] virtual bool OverlapPoint(Vector2f point) = 0;
        [[nodiscard]] bool OverlapsCollider(const Collider& other) const;

        [[nodiscard]] virtual std::optional<HitResult> CheckForRayCast(const Vector2f& origin,const Vector2f& direction) const = 0;
        [[nodiscard]] virtual std::optional<HitResult> CheckForCircleCast(const Vector2f& origin,const Vector2f& direction,const float& radius) const = 0;

        [[nodiscard]] virtual bool OverlapsCollider(const AABB& other) const = 0;
        [[nodiscard]] virtual bool OverlapsCollider(const OBB& other) const = 0;
        [[nodiscard]] virtual bool OverlapsCollider(const Circle& other) const = 0;

};


#endif //TESTSFML_SHAPE_H