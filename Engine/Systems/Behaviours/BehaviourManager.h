//
// Created by Nathan on 26/08/2025.
//

#ifndef TESTSFML_BEHAVIOURMANAGER_H
#define TESTSFML_BEHAVIOURMANAGER_H
#include "../../Nodes/SceneNodes/Behaviours/BehaviourNode.h"


class BehaviourManager
{
public:
    BehaviourManager();
    ~BehaviourManager();
    static BehaviourManager* Instance;

    void StartAllBehavioursInOrder();
    void UpdateAllBehavioursInOrder(float deltatime) const;
    void PrintAllBehavioursInOrder() const;

    void RegisterBehaviour(BehaviourNode* behaviour);
    void UnregisterBehaviour(BehaviourNode* behaviour);
    void ChangeBehaviourExecutionOrder(BehaviourNode* behaviour);

private:
    std::vector<BehaviourNode*> behaviours;
};


#endif //TESTSFML_BEHAVIOURMANAGER_H
