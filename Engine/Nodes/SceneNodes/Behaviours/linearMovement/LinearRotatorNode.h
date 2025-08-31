//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_LINEARROTATORNODE_H
#define TESTSFML_LINEARROTATORNODE_H
#include "../BehaviourNode.h"


class LinearRotatorNode : public BehaviourNode
{
public:
    LinearRotatorNode(string Name = DEFAULT_NODE_NAME,float AngularSpeedDegreesPerSecond = 360);
    void Update(float deltatime) override;
    void Start() override;
    bool LoadXmlAttribute(string key, string value) override;

    float DegreesPerSecond;
};


#endif //TESTSFML_LINEARROTATORNODE_H