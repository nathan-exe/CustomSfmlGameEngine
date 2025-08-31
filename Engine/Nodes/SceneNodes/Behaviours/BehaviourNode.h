//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_BEHAVIOURNODE_H
#define TESTSFML_BEHAVIOURNODE_H
#include "../SceneNode.h"


class BehaviourNode : public SceneNode
{
public :
    BehaviourNode(string name = DEFAULT_NODE_NAME) ;
    ~BehaviourNode();
    virtual void Update(float deltatime) = 0;
    virtual void Start() = 0;

    bool LoadXmlAttribute(string key, string value) override;

    bool hasBeenStarted = false;
    int ExecutionOrder;
};


#endif //TESTSFML_BEHAVIOURNODE_H