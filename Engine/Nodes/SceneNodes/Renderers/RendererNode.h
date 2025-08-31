//
// Created by Nathan on 17/08/2025.
//

#ifndef TESTSFML_RENDERERNODE_H
#define TESTSFML_RENDERERNODE_H
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../CameraNode.h"
//class RendererManager;



class RendererNode : public SceneNode
{
public:
    RendererNode(const std::string& name = DEFAULT_NODE_NAME);
    ~RendererNode();

    virtual void Initialize();
    virtual void Draw(CameraNode& Camera) = 0;

    bool LoadXmlAttribute(string key, string value) override;

    int Layer = 0;
};


#endif //TESTSFML_RENDERERNODE_H