//
// Created by Megaport on 31/08/2025.
//

#ifndef TESTSFML_TILEMAPRENDERERNODE_H
#define TESTSFML_TILEMAPRENDERERNODE_H
#include "TilemapNode.h"
#include "../Renderers/RendererNode.h"


class TilemapRendererNode : RendererNode
{
public:
    void Draw(CameraNode& Camera) override;
    void Initialize() override;

private :
    void LoadTileSet();

private:
    TilemapNode* _tilemap;
    std::map<int,sf::Drawable> _tileVisuals;
};


#endif //TESTSFML_TILEMAPRENDERERNODE_H