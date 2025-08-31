//
// Created by Nathan on 17/08/2025.
//

#include "RendererNode.h"
#include "../../../../Engine/Systems/Rendering/RendererManager.h"

RendererNode::RendererNode(const std::string& name) : SceneNode(name)
{
    RendererManager::Instance->RegisterRenderer(this);
}

RendererNode::~RendererNode()
{
    RendererManager::Instance->UnregisterRenderer(this);
}

void RendererNode::Initialize()
{
}

bool RendererNode::LoadXmlAttribute(string key, string value)
{
    bool result = SceneNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0==key.compare("layer")))
        {
            Layer = StringConversions::IntFromString(value);
        }
    }
    return result ;
}


