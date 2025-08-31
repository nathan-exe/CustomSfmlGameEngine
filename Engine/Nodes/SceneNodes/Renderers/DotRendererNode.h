//
// Created by Nathan on 25/08/2025.
//

#ifndef TESTSFML_DOTRENDERERNODE_H
#define TESTSFML_DOTRENDERERNODE_H
#include "RendererNode.h"


class DotRendererNode : public RendererNode
{
public:
    DotRendererNode(const std::string& name = DEFAULT_NODE_NAME,sf::Color color = sf::Color::White);
    void Draw(CameraNode& Camera) override;

    bool LoadXmlAttribute(string key, string value) override;

private:
    sf::Color color;
};


#endif //TESTSFML_DOTRENDERERNODE_H