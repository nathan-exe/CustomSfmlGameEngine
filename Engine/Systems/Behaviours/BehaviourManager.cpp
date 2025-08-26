//
// Created by Nathan on 26/08/2025.
//


#include "BehaviourManager.h"

BehaviourManager* BehaviourManager::Instance = nullptr;

BehaviourManager::BehaviourManager()
{
    Instance = this;
}

BehaviourManager::~BehaviourManager()
{
    if (Instance == this)
    Instance = nullptr;
}

void BehaviourManager::StartAllBehavioursInOrder()
{
    for (BehaviourNode* behaviour : behaviours)
    {
        behaviour->hasBeenStarted = true;
        behaviour->Start();
    }
}

void BehaviourManager::UpdateAllBehavioursInOrder(float deltatime) const
{
    for (BehaviourNode* behaviour : behaviours)
    {
        if (!behaviour->hasBeenStarted)
        {
            behaviour->hasBeenStarted = true;
            behaviour->Start();
        }
        behaviour->Update(deltatime);
    }
}

void BehaviourManager::PrintAllBehavioursInOrder() const
{
    cout<<"all behaviours in order : \n";
    for (BehaviourNode* behaviour : behaviours)
    {
        cout<<behaviour->Name<<" (order : "<<behaviour->ExecutionOrder<<" ) \n";
    }
    cout.flush();
}

void BehaviourManager::RegisterBehaviour(BehaviourNode* behaviour)
{
    behaviours.insert(
        std::upper_bound(
            behaviours.begin(),behaviours.end(),
                behaviour,
                [](const BehaviourNode* a, const BehaviourNode* b)
                {
                    return a->ExecutionOrder>b->ExecutionOrder;
                })
            ,behaviour);
}

void BehaviourManager::UnregisterBehaviour(BehaviourNode* behaviour)
{
    behaviours.erase(
        std::remove(behaviours.begin(), behaviours.end(), behaviour),
        behaviours.end());
}

void BehaviourManager::ChangeBehaviourExecutionOrder(BehaviourNode* behaviour)
{
    //todo : ici
}
