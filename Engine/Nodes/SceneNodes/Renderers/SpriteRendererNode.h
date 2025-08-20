//
// Created by Nathan on 17/08/2025.
//

#ifndef TESTSFML_SPRITERENDERERNODE_H
#define TESTSFML_SPRITERENDERERNODE_H
#include "RendererNode.h"
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include "../CameraNode.h"
#include "../../../Rendering/SpriteManager.h"

class SpriteRendererNode : public RendererNode
{
public :
    SpriteRendererNode(const std::string& name,const std::string& SpriteName);
    void Draw(CameraNode& Camera) override;

private :
    string spriteName;
};


#endif //TESTSFML_SPRITERENDERERNODE_H