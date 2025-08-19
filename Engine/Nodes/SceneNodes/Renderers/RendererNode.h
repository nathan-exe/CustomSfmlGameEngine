//
// Created by Nathan on 17/08/2025.
//

#ifndef TESTSFML_RENDERERNODE_H
#define TESTSFML_RENDERERNODE_H
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../CameraNode.h"
//#include "../../../../Engine/Rendering/RendererManager.h"

class RendererNode : public SceneNode
{
public:
    RendererNode(const std::string& name);
    ~RendererNode();
    virtual void Draw(sf::RenderWindow& window,CameraNode& Camera) = 0;

public:
    int layer = 0;
};


#endif //TESTSFML_RENDERERNODE_H