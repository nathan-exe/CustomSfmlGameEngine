//
// Created by Nathan on 26/08/2025.
//

#include "CameraBehaviour.h"

#include "../../../Engine/Utils/Math.h"

void CameraBehaviour::Update(float deltatime)
{
    sf::Vector2f mousePosition = static_cast<Vector2f>(
    sf::Mouse::getPosition(
        *static_cast<sf::RenderWindow*>(cam->renderTarget)));

    //compute target position
    Vector2f normalizedMousePosition = {
        mousePosition.x/cam->renderTarget->getSize().x,
        1.0f-mousePosition.y/cam->renderTarget->getSize().y
    };
    Vector2f offset = (normalizedMousePosition*2.0f - Vector2f{1,1})*1.5f;

    //damp toward target position
    cam->SetLocalPosition(Math::Damp(cam->GetLocalPosition(),offset,5,deltatime));

}

void CameraBehaviour::Start()
{
    cam = static_cast<CameraNode*>(Parent);
}
