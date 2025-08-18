//
// Created by Nathan on 17/08/2025.
//

#ifndef TESTSFML_RENDERERNODE_H
#define TESTSFML_RENDERERNODE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>

#include "../SceneNode.h"


class RendererNode : public SceneNode
{
public:
    RendererNode(const string& name);
    ~RendererNode();
    virtual void Draw(sf::RenderWindow& window) = 0;

public:
    int layer = 0;
};


#endif //TESTSFML_RENDERERNODE_H