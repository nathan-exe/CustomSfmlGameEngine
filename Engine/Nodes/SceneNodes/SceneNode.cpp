//
// Created by Nathan on 13/08/2025.
//

#include "SceneNode.h"




SceneNode::SceneNode(const string& name) : Node(name)
{

}

sf::Transform SceneNode::GetLocalTransform() const
{
    sf::Transform localTransform = sf::Transform::Identity;
    localTransform.scale(_localScale);
    localTransform.translate(_localPosition);
    localTransform.rotate(_localAngle);
    return localTransform;
}

sf::Transform SceneNode::GetWorldTransform() const
{
    sf::Transform localTransform = GetLocalTransform();

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
    _localAngle = Angle::Zero;
    _localPosition = {0,0};
    _localScale = {1,1};
}


void SceneNode::Rotate(const Angle& angle)
{
    _localAngle += angle;
}

void SceneNode::Scale(const sf::Vector2f& scale)
{
    _localScale.x *= scale.x;
    _localScale.y *= scale.y;
}

Vector2f SceneNode::GetLocalPosition() const
{
    return _localPosition;
}

Vector2f SceneNode::GetLocalScale() const
{
    return _localScale;
}

Angle SceneNode::GetLocalAngle() const
{
    return _localAngle;
}

Vector2f SceneNode::GetWorldPosition() const
{
    Transform localToWorld = GetWorldTransform();
    return localToWorld * _localPosition;
}

Angle SceneNode::GetWorldAngle() const
{
    if (Parent==nullptr) return _localAngle;
    return static_cast<SceneNode*>(Parent)->GetWorldAngle() + _localAngle;
}

void SceneNode::SetLocalPosition(const Vector2f& newPosition)
{
    _localPosition = newPosition;
}

void SceneNode::SetLocalScale(const Vector2f& newScale)
{
    _localScale = newScale;
}

void SceneNode::SetLocalAngle(const Angle& angle)
{
    _localAngle = angle;
}

void SceneNode::SetWorldPosition(const Vector2f& newPosition)
{
    Transform worldToLocal = GetWorldToLocalTransform();
    _localPosition = worldToLocal.transformPoint(newPosition);//pas sur que ça marche
}

void SceneNode::SetWorldAngle(const Angle& angle)
{
    Angle currentWorldAngle = GetWorldAngle();
    Angle Offset = angle - currentWorldAngle;
    _localAngle += Offset;//pas sur que ça marche
}

bool SceneNode::LoadXmlAttribute(string key, string value)
{
    bool success = false;
    if ((success = 0 == key.compare("name")))
    {
        Name = value;
        cout<<Name;
    }
    else if ((success = 0 == key.compare("localTransform")))
    {
        char del = ',';
        string temp;
        std::stringstream stream(value);

        std::getline(stream, temp, del);
        _localPosition.x = StringConversions::FloatFromString(temp);
        std::getline(stream, temp, del);
        _localPosition.y = StringConversions::FloatFromString(temp);
        std::getline(stream, temp, del);
        _localScale.x = StringConversions::FloatFromString(temp);
        std::getline(stream, temp, del);
        _localScale.y = StringConversions::FloatFromString(temp);
        std::getline(stream, temp, del);
        _localAngle = StringConversions::AngleFromString(temp);
        cout<<"local position : "<<_localPosition.x<<" "<<_localPosition.y<<endl;
        cout<<"local scale : "<<_localScale.x<<" "<<_localScale.y<<endl;
    }
    return success;
}


void SceneNode::Move(const sf::Vector2f& offset)
{
    //cout<<"world offset : "<<offset.x<<','<<offset.y<<endl;
    Vector2 worldPosition = GetWorldPosition();
    worldPosition+=offset;
    SetWorldPosition(worldPosition);

}






