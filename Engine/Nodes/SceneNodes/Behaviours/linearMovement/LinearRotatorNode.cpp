//
// Created by Nathan on 26/08/2025.
//

#include "LinearRotatorNode.h"

LinearRotatorNode::LinearRotatorNode(string Name,float AngularSpeedDegreesPerSecond) : BehaviourNode("LinearRotatorNode")
{
    DegreesPerSecond = AngularSpeedDegreesPerSecond;
}

void LinearRotatorNode::Update(float deltatime)
{
    Rotate(sf::degrees(deltatime*DegreesPerSecond));
}

void LinearRotatorNode::Start()
{
}
