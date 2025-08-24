//
// Created by Nathan on 17/08/2025.
//

#include "SpriteRendererNode.h"

SpriteRendererNode::SpriteRendererNode(const std::string& name, const std::string& SpriteName) : RendererNode(name)
{
    cout<<"constructor SpriteRenderer. sprintename : "<<SpriteName<<endl;
    spriteName = SpriteName;
}

void SpriteRendererNode::Draw(CameraNode& Camera)
{
    sf::Sprite sprite = SpriteManager::Instance->GetSprite(spriteName);

    sf::Transform worldToScreen =  (Camera.WorldToScreenMatrix());
    sf::Transform texelToWorld = sf::Transform::Identity;
    texelToWorld.scale(Vector2<float>(1.0f / Camera.Current->PixelsPerUnit,1.0f/ Camera.Current->PixelsPerUnit));

    //todo : origine du sprite

    Camera.renderTarget->draw(sprite,worldToScreen * GetWorldToLocalTransform()*texelToWorld);
}
