//
// Created by Nathan on 17/08/2025.
//

#include "RendererNode.h"

#include "../../../Rendering/RendererManager.h"

RendererNode::RendererNode(const string& name) : SceneNode(name)
{
    cout<<"constructor Renderer"<<endl;
    RendererManager::Instance->RegisterRenderer(this);
}

RendererNode::~RendererNode()
{
    RendererManager::Instance->UnregisterRenderer(this);
}
