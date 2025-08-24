//
// Created by Nathan on 17/08/2025.
//

#include "RendererNode.h"
#include "../../../../Engine/Rendering/RendererManager.h"

RendererNode::RendererNode(const std::string& name) : SceneNode(name)
{
    RendererManager::Instance->RegisterRenderer(this);
}

RendererNode::~RendererNode()
{
    RendererManager::Instance->UnregisterRenderer(this);
}
