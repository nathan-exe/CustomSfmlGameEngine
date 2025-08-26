//
// Created by Nathan on 19/08/2025.
//

#include "CameraNode.h"

CameraNode::CameraNode(const string& name,sf::RenderTarget* RenderTarget) : SceneNode(name)
{
    this->renderTarget = RenderTarget;
    if (Current==nullptr) Current = this;
}

CameraNode* CameraNode::Current = nullptr;

sf::Transform CameraNode::WorldToScreenMatrix() const
{
    float heightRatioFromWorldToWindow = renderTarget->getSize().y/(worldHeight); //bien
    float AspectRatio = static_cast<float>(renderTarget->getSize().x)/static_cast<float>(renderTarget->getSize().y);
    float worldWidth = worldHeight * AspectRatio;

    Transform matrix = GetWorldToLocalTransform();

    Transform scaleMatrix = Transform::Identity;
    scaleMatrix.scale(Vector2<float>(heightRatioFromWorldToWindow,-heightRatioFromWorldToWindow));
    matrix = scaleMatrix*matrix ;

    Transform translation = Transform::Identity;
    translation.translate({worldWidth*.5f,-worldHeight*.5f});//la translation est affectée par le scale donc faut la mettre après
    matrix = matrix * translation;

    return matrix;
}
