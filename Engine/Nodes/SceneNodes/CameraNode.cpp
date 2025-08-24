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
    //todo: pb ici
    sf::Transform view = sf::Transform::Identity;

    float heightRatioFromWorldToWindow = renderTarget->getSize().y/(worldHeight); //bien


    //cout<<"window size : "<<renderTarget->getSize().x<<','<<renderTarget->getSize().y<<endl;
    cout<<"Camera worldHeight : "<<worldHeight<<endl;
    cout<<"Pixels Per Unit : " << PixelsPerUnit;
    cout<<"heightRatioFromWorldToWindow : "<<heightRatioFromWorldToWindow<<endl;

    //view.scale(Vector2<float>(heightRatioFromWorldToWindow,heightRatioFromWorldToWindow*ViewAspectRatio));
    sf::Transform world = GetLocalToWorldTransform();
    world.scale(Vector2<float>(heightRatioFromWorldToWindow,heightRatioFromWorldToWindow));
    return world * view;
}
