//
// Created by Nathan on 17/08/2025.
//

#include "SpriteRendererNode.h"

SpriteRendererNode::SpriteRendererNode(const std::string& name, const std::string& SpriteName) : RendererNode(name)
{
    cout<<"constructor SpriteRenderer. sprintename : "<<SpriteName<<endl;
    spriteName = SpriteName;
}

void SpriteRendererNode::Draw(sf::RenderWindow& window,CameraNode& Camera)
{
    sf::Sprite sprite = SpriteManager::Instance->GetSprite(spriteName);

    window.draw(sprite,GetScreenTransform(Camera.GetViewMatrix()));
}
