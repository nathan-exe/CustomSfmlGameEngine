//
// Created by Nathan on 17/08/2025.
//

#include "SpriteRendererNode.h"

#include "../../../Rendering/SpriteManager.h"

SpriteRendererNode::SpriteRendererNode(const std::string& name, const std::string& SpriteName) : RendererNode(name)
{
    cout<<"constructor SpriteRenderer. sprintename : "<<SpriteName<<endl;
    spriteName = SpriteName;
}

void SpriteRendererNode::Draw(sf::RenderWindow& window)
{
    sf::Sprite sprite = SpriteManager::Instance->GetSprite(spriteName);

    sprite.setPosition(getPosition());
    sprite.setRotation(getRotation());
    sprite.setScale(getScale());

    window.draw(sprite);
}
