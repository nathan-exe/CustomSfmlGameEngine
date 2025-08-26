//
// Created by Nathan on 19/08/2025.
//

#ifndef TESTSFML_CAMERANODE_H
#define TESTSFML_CAMERANODE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Window.hpp>
#include "SceneNode.h"



class CameraNode : public SceneNode
{
public :
    CameraNode(const std::string& name,sf::RenderTarget* RenderTarget);
    static CameraNode* Current;

    [[nodiscard]] Transform WorldToScreenMatrix() const;
    [[nodiscard]] Transform ScreenToWorldMatrix() const;

    float worldHeight = 0;
    const int PixelsPerUnit = 50;

public :
    sf::RenderTarget* renderTarget = nullptr;

};


#endif //TESTSFML_CAMERANODE_H