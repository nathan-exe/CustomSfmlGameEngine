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

bool LinearRotatorNode::LoadXmlAttribute(string key, string value)
{
    bool result = BehaviourNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0 == key.compare("degreesPerSecond")))
        {
            DegreesPerSecond = StringConversions::FloatFromString(value);
        }
    }
    return result ;
}
