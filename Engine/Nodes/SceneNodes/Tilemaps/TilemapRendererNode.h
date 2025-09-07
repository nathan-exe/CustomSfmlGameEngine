//
// Created by Megaport on 31/08/2025.
//

#ifndef TESTSFML_TILEMAPRENDERERNODE_H
#define TESTSFML_TILEMAPRENDERERNODE_H
#include "TilemapNode.h"
#include "../Renderers/RendererNode.h"

using sf::Drawable;

class TilemapRendererNode : public RendererNode
{
public:
    ~TilemapRendererNode();
    void Draw(CameraNode& Camera) override;
    void Initialize() override;

private :
    void LoadTileSet();

private:
    TilemapNode* _tilemap = nullptr;
    std::map<int,Drawable*> _tileVisuals;
};


#endif //TESTSFML_TILEMAPRENDERERNODE_H