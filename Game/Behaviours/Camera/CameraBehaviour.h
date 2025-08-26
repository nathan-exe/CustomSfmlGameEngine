//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_CAMERABEHAVIOUR_H
#define TESTSFML_CAMERABEHAVIOUR_H
#include "../../../Engine/Nodes/SceneNodes/CameraNode.h"
#include "../../../Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.h"


class CameraBehaviour : public BehaviourNode
{
public:
    CameraBehaviour(const string& name)
        : BehaviourNode(name)
    {
    }

    void Update(float deltatime) override;
    void Start() override;

private:
        CameraNode* cam;
};


#endif //TESTSFML_CAMERABEHAVIOUR_H