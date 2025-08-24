//
// Created by Nathan on 13/08/2025.
//

#ifndef TESTSFML_SCENENODE_H
#define TESTSFML_SCENENODE_H


#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Angle.hpp>
#include "../../Utils/DataSerializer.h"
#include "../Node.h"

using sf::Vector2,sf::Angle;

class SceneNode : public Node
{
public:
    SceneNode(const string& name);

    sf::Transform GetLocalToWorldTransform() const;
    sf::Transform GetWorldToLocalTransform() const;
    void SetWorldTransform(const sf::Transform& newWorldTransform);
    void Move(const sf::Vector2f& offset);
    void Rotate(float angle);
    void SetLocalTransform(const sf::Transform& newLocalTransform);

private :
    sf::Transform localTransform = sf::Transform::Identity;


};


#endif //TESTSFML_SCENENODE_H