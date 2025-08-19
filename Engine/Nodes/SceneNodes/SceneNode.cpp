//
// Created by Nathan on 13/08/2025.
//

#include "SceneNode.h"


SceneNode::SceneNode(const string& name) : Node(name)
{

}

sf::Transform SceneNode::GetLocalToWorldTransform() const
{
    if (Parent == nullptr) return localTransform;
    return localTransform * static_cast<SceneNode*>(Parent)->GetLocalToWorldTransform();
}

sf::Transform SceneNode::GetWorldToLocalTransform() const
{
    return GetLocalToWorldTransform().getInverse();
}

void SceneNode::SetWorldTransform(const sf::Transform& newWorldTransform)
{
    localTransform = newWorldTransform * GetWorldToLocalTransform();
}

sf::Transform SceneNode::GetScreenTransform(const sf::Transform& viewMatrix) const
{
    return viewMatrix * GetLocalToWorldTransform();
}





