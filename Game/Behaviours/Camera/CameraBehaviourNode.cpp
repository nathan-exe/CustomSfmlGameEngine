//
// Created by Nathan on 26/08/2025.
//

#include "CameraBehaviourNode.h"

#include "../../../Engine/Utils/Math.h"

void CameraBehaviourNode::Update(float deltatime)
{

    //keyboard movement
    constexpr float moveSpeed = 15;
    Vector2f movementInput = {
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)? 1.0f : 0.0f) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)? 1.0f : 0.0f),
        (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)? 1.0f : 0.0f) - (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)? 1.0f : 0.0f),
    };
    movementInput *= moveSpeed * deltatime;

    static_cast<SceneNode*>(cam->Parent)->Move(movementInput);
    cam->Move(-movementInput);

    //mouse movement
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

    //zoom
    float zoomDelta = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)?1:0)-(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)?1:0);
    this->cam->worldHeight-=zoomDelta*deltatime*10;
}

void CameraBehaviourNode::Start()
{
    if (cam == nullptr)
    cam = static_cast<CameraNode*>(Parent);
}
