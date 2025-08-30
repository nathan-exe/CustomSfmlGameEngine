//
// Created by Nathan on 17/08/2025.
//

#include "SpriteRendererNode.h"

SpriteRendererNode::SpriteRendererNode(const std::string& name, const std::string& SpriteName) : RendererNode(name)
{
    cout<<"constructor SpriteRenderer. sprintename : "<<SpriteName<<endl;
    _spriteName = SpriteName;
}

void SpriteRendererNode::Draw(CameraNode& Camera)
{
    sf::Sprite sprite = SpriteManager::Instance->GetSprite(_spriteName);

    sf::Transform texelToLocal = sf::Transform::Identity;
    float invPixelsPerUnits = 1.0f/Camera.PixelsPerUnit;//suggestion : sauvegarder ça dans la cam direct
    texelToLocal.scale({invPixelsPerUnits,-invPixelsPerUnits});
    //texelToLocal.translate(-sprite.getOrigin());

    sf::Transform worldToScreen =  (Camera.WorldToScreenMatrix());

    sf::Transform localToScreen = worldToScreen * GetWorldTransform() * texelToLocal;
    //cout<<"world transform : \n"<<DataSerializer::TransformToString(localToScreen);
    //cout<<"screen transform : \n"<<DataSerializer::TransformToString(localToScreen);

    Camera.renderTarget->draw(sprite,localToScreen);
}

bool SpriteRendererNode::LoadXmlAttribute(string key, string value)
{
    bool result = RendererNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0==key.compare("spriteName")))
        {
            _spriteName = value;
        }
    }
    return result ;
}
