//
// Created by Nathan on 21/09/2025.
//

#include "Physics.h"

#include <set>

#include "HitResult.h"
#include "Shapes/Collider.h"
#include "Shapes/Circle.h"
#include <Vector>

int a()
{
    Collider* circle = new Circle();
    Collider* boule = new Circle();

    circle->CastAgainstShape(*boule);
    return 0;
}