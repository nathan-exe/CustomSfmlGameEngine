//
// Created by Nathan on 26/08/2025.
//

#include "BehaviourNode.h"

#include "../../../Systems/Behaviours/BehaviourManager.h"

BehaviourNode::BehaviourNode(string name) : SceneNode(name)
{
    BehaviourManager::Instance->RegisterBehaviour(this);
}

BehaviourNode::~BehaviourNode()
{
    BehaviourManager::Instance->UnregisterBehaviour(this);
}

bool BehaviourNode::LoadXmlAttribute(string key, string value)
{
    bool result = SceneNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0==key.compare("executionOrder")))
        {
            ExecutionOrder = StringConversions::IntFromString(value);
        }
    }
    return result ;
}

