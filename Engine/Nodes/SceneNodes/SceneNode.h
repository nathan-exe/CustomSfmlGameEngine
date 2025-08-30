//
// Created by Nathan on 13/08/2025.
//

#ifndef TESTSFML_SCENENODE_H
#define TESTSFML_SCENENODE_H


#include <SFML/Graphics/Transform.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Angle.hpp>
#include "../../Utils/StringConversions.h"
#include "../Node.h"

using sf::Vector2,sf::Angle,sf::Vector2f,sf::Transform;

class SceneNode : public Node
{
public:
    SceneNode(const string& name);

    //transformations
    [[nodiscard]] Transform GetLocalTransform() const;
    [[nodiscard]] Transform GetWorldTransform() const;
    [[nodiscard]] Transform GetWorldToLocalTransform() const;
    void ResetLocalTransform();

    void Move(const Vector2f& offset);
    void Rotate(const Angle& angle);
    void Scale(const Vector2f& scale);

    [[nodiscard]] Vector2f GetLocalPosition() const;
    [[nodiscard]] Vector2f GetLocalScale() const;
    [[nodiscard]] Angle GetLocalAngle() const;

    [[nodiscard]] Vector2f GetWorldPosition() const;
    [[nodiscard]] Angle GetWorldAngle() const;

    void SetLocalPosition(const Vector2f& newPosition);
    void SetLocalScale(const Vector2f& newScale);
    void SetLocalAngle(const Angle& angle);

    void SetWorldPosition(const Vector2f& newPosition);
    void SetWorldAngle(const Angle& angle);
//xml
    virtual bool LoadXmlAttribute(string key, string value);

private :
    Angle _localAngle = sf::degrees(0);
    Vector2f _localPosition = {0,0};
    Vector2f _localScale = {1,1};

};


#endif //TESTSFML_SCENENODE_H