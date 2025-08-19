//
// Created by Nathan on 19/08/2025.
//

#include "CameraNode.h"

CameraNode::CameraNode(string name,sf::Window* window) : SceneNode(name)
{
}

CameraNode* CameraNode::Current = nullptr;

sf::Transform CameraNode::GetViewMatrix() const
{
    float windowAspectRatio = window->getSize().x / window->getSize().y;
    sf::Transform view = sf::Transform::Identity;

    float heightRatioFromWorldToWindow = window->getSize().y/worldHeight;
    view.scale(Vector2<float>(heightRatioFromWorldToWindow,heightRatioFromWorldToWindow*windowAspectRatio));

    return GetLocalToWorldTransform() * view;
}
