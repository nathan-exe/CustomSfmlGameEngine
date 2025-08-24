//
// Created by Nathan on 25/08/2025.
//

#include "DotRendererNode.h"

DotRendererNode::DotRendererNode(const std::string& name, sf::Color color)
 : RendererNode(name)
{
    this->color = color;
}

void DotRendererNode::Draw(CameraNode& Camera)
{
    sf::CircleShape circle = sf::CircleShape(.1f);
    //color.a = 100;
    circle.setFillColor(color);
    circle.setOrigin({circle.getRadius(),circle.getRadius()});
    sf::Transform worldToScreen =  (Camera.WorldToScreenMatrix());

    sf::Transform localToScreen = worldToScreen * GetLocalToWorldTransform();

    //Camera.renderTarget->draw(circle,localToScreen);
}


