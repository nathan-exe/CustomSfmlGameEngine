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
    //todo : bug ici
    //ça pue.
    cout<<"world to local : \n"<<DataSerializer::TransformToString(GetWorldToLocalTransform());
    localTransform = localTransform * newWorldTransform * GetWorldToLocalTransform() ;
}

void SceneNode::Move(const sf::Vector2f& offset)
{
    cout<<"identity : \n"<< DataSerializer::TransformToString(sf::Transform::Identity)<<endl;
    cout<<"local : \n"<< DataSerializer::TransformToString(localTransform)<<endl;
    sf::Transform world = GetLocalToWorldTransform();
    cout<<"world : \n"<< DataSerializer::TransformToString(world)<<endl;
    //sf::Transform world = localTransform;//();
    //cout<<world.getMatrix();
    world.translate(offset);


    //localTransform = world;
    SetWorldTransform(world);

    cout<<"new world : \n"<< DataSerializer::TransformToString(world)<<endl;
    cout<<"new local : \n"<< DataSerializer::TransformToString(localTransform)<<endl;
}






