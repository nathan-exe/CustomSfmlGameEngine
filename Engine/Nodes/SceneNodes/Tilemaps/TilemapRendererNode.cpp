//
// Created by Megaport on 31/08/2025.
//

#include "TilemapRendererNode.h"

void TilemapRendererNode::Draw(CameraNode& Camera)
{

}

void TilemapRendererNode::Initialize()
{
    RendererNode::Initialize();
    _tilemap = static_cast<TilemapNode*>(Parent);
}
