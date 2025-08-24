//
// Created by Nathan on 25/08/2025.
//

#include "DotRendererNode.h"

void DotRendererNode::Draw(CameraNode& Camera)
{
    sf::CircleShape circle = sf::CircleShape(.1f);
    circle.setFillColor(sf::Color::Red);
    circle.setOrigin({circle.getRadius()*.5f,circle.getRadius()*.5f});
    sf::Transform worldToScreen =  (Camera.WorldToScreenMatrix());

    sf::Transform localToScreen = worldToScreen * GetLocalToWorldTransform();

    Camera.renderTarget->draw(circle,localToScreen);
}
