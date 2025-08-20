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
    cout<<"sprite : "<<&sprite<<endl;
    cout<<"view Matrix : "<<Camera.GetViewMatrix().getMatrix()<<endl;
    Camera.renderTarget->draw(sprite,GetScreenTransform(Camera.GetViewMatrix()));
}
