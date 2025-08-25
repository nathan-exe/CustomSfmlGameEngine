//
// Created by Nathan on 13/08/2025.
//

#include "SceneNode.h"




SceneNode::SceneNode(const string& name) : Node(name)
{

}

sf::Transform SceneNode::GetWorldTransform() const
{
    sf::Transform localTransform = sf::Transform::Identity;
    localTransform.scale(localScale);
    localTransform.rotate(localAngle);
    localTransform.translate(localPosition);
    //cout<<"local transform : \n"<<DataSerializer::TransformToString(localTransform)<<endl;

    if (Parent == nullptr) return localTransform;
    return static_cast<SceneNode*>(Parent)->GetWorldTransform()*localTransform ;
}

sf::Transform SceneNode::GetWorldToLocalTransform() const
{
    return GetWorldTransform().getInverse();
}

void SceneNode::ResetLocalTransform()
{
    localAngle = Angle::Zero;
    localPosition = {0,0};
    localScale = {1,1};
}


void SceneNode::Rotate(const Angle& angle)
{
    localAngle += angle;
}

void SceneNode::Scale(const sf::Vector2f& scale)
{
    localScale.x *= scale.x;
    localScale.y *= scale.y;
}

Vector2f SceneNode::GetLocalPosition() const
{
    return localPosition;
}

Vector2f SceneNode::GetLocalScale() const
{
    return localScale;
}

Angle SceneNode::GetLocalAngle() const
{
    return localAngle;
}

Vector2f SceneNode::GetWorldPosition() const
{
    Transform localToWorld = GetWorldTransform();
    return localToWorld * localPosition;
}

Angle SceneNode::GetWorldAngle() const
{
    if (Parent==nullptr) return localAngle;
    return static_cast<SceneNode*>(Parent)->GetWorldAngle() + localAngle;
}

void SceneNode::SetLocalPosition(const Vector2f& newPosition)
{
    localPosition = newPosition;
}

void SceneNode::SetLocalScale(const Vector2f& newScale)
{
    localScale = newScale;
}

void SceneNode::SetLocalAngle(const Angle& angle)
{
    localAngle = angle;
}

void SceneNode::SetWorldPosition(const Vector2f& newPosition)
{
    Transform worldToLocal = GetWorldToLocalTransform();
    localPosition = worldToLocal.transformPoint(newPosition);//pas sur que ça marche
}

void SceneNode::SetWorldAngle(const Angle& angle)
{
    Angle currentWorldAngle = GetWorldAngle();
    Angle Offset = angle - currentWorldAngle;
    localAngle += Offset;//pas sur que ça marche
}


void SceneNode::Move(const sf::Vector2f& offset)
{
    cout<<"world offset : "<<offset.x<<','<<offset.y<<endl;
    Vector2 worldPosition = GetWorldPosition();
    worldPosition+=offset;
    SetWorldPosition(worldPosition);

}






