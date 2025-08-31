//
// Created by Nathan on 26/08/2025.
//

#include "CameraBehaviourNode.h"

#include "../../../Engine/Utils/Math.h"

void CameraBehaviourNode::Update(float deltatime)
{
    sf::Vector2f mousePosition = static_cast<Vector2f>(
    sf::Mouse::getPosition(
        *static_cast<sf::RenderWindow*>(cam->renderTarget)));

    //compute target position
    Vector2f normalizedMousePosition = {
        mousePosition.x/cam->renderTarget->getSize().x,
        1.0f-mousePosition.y/cam->renderTarget->getSize().y
    };
    Vector2f offset = (normalizedMousePosition*1.0f - Vector2f{1,1})*1.5f;

    //damp toward target position
    cam->SetLocalPosition(Math::Damp(cam->GetLocalPosition(),offset,5,deltatime));

}

void CameraBehaviourNode::Start()
{
    if (cam == nullptr)
    cam = static_cast<CameraNode*>(Parent);
}
