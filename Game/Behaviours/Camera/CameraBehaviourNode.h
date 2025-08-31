//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_CAMERABEHAVIOUR_H
#define TESTSFML_CAMERABEHAVIOUR_H
#include "../../../Engine/Nodes/SceneNodes/CameraNode.h"
#include "../../../Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.h"


class CameraBehaviourNode : public BehaviourNode
{
public:
    CameraBehaviourNode(const string& name = DEFAULT_NODE_NAME,CameraNode* cam = nullptr)
        : BehaviourNode(name)
    {
        this->cam = cam;
    }

    void Update(float deltatime) override;
    void Start() override;

private:
        CameraNode* cam = nullptr;
};


#endif //TESTSFML_CAMERABEHAVIOUR_H