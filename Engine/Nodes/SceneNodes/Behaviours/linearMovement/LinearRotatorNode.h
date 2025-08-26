//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_LINEARROTATORNODE_H
#define TESTSFML_LINEARROTATORNODE_H
#include "../BehaviourNode.h"


class LinearRotatorNode : public BehaviourNode
{
public:
    LinearRotatorNode(string Name,float AngularSpeedDegreesPerSecond);
    void Update(float deltatime) override;
    void Start() override;

public:
    float DegreesPerSecond;
};


#endif //TESTSFML_LINEARROTATORNODE_H