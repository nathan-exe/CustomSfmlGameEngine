//
// Created by Nathan on 26/08/2025.
//

#include "BehaviourNode.h"

#include "BehaviourManager.h"

BehaviourNode::BehaviourNode(string name) : SceneNode(name)
{
    BehaviourManager::Instance->RegisterBehaviour(this);
}

BehaviourNode::~BehaviourNode()
{
    BehaviourManager::Instance->UnregisterBehaviour(this);
}

