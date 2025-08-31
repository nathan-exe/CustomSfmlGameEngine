//
// Created by Nathan on 25/08/2025.
//

#include "DotRendererNode.h"

DotRendererNode::DotRendererNode(const std::string& name, sf::Color color) : RendererNode(name)
{
}

void DotRendererNode::Draw(CameraNode& Camera)
{
#ifdef SFML_DEBUG
    sf::CircleShape circle = sf::CircleShape(.1f);
    circle.setFillColor(color);
    circle.setOrigin({circle.getRadius(),circle.getRadius()});

    Transform worldToScreen =  (Camera.WorldToScreenMatrix());
    Transform localToScreen = worldToScreen * GetWorldTransform();

    Camera.renderTarget->draw(circle,localToScreen);
#endif
}

bool DotRendererNode::LoadXmlAttribute(string key, string value)
{
    bool result = RendererNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0==key.compare("color")))
        {
            color = StringConversions::ColorFromString(value);
        }
    }
    return result ;
}




