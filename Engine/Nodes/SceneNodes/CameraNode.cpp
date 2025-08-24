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

    sf::Transform matrix = GetLocalToWorldTransform();
    cout<<"camera world : \n"<<DataSerializer::TransformToString(matrix);

    float AspectRatio = renderTarget->getSize().x/renderTarget->getSize().y;
    float worldWidth = worldHeight * AspectRatio;
    matrix.scale(Vector2<float>(heightRatioFromWorldToWindow,-heightRatioFromWorldToWindow));
    cout<<"scaled world : \n"<<DataSerializer::TransformToString(matrix);

    matrix.translate({worldWidth*.5f,-worldHeight*.5f});//la translation est affectée par le scale donc faut la mettre après
    cout<<"centered world : \n"<<DataSerializer::TransformToString(matrix);

    return matrix;
}
