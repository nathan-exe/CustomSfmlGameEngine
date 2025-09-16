//
// Created by Megaport on 31/08/2025.
//

#ifndef TESTSFML_TILEMAPRENDERERNODE_H
#define TESTSFML_TILEMAPRENDERERNODE_H
#include "TilemapNode.h"
#include "../Renderers/RendererNode.h"
#include "../../../Systems/AutoTiles/AutoTile.h"
#include "../../../Utils/StringConversions.h"
#include <fstream>

using sf::Drawable;

///le tilemap renderer est propriétaire de tous les sprites et textures qu'il utilise.
///si deux tilemap renderers utilisent les même sprites, ça sera dupliqué.
///c'est pas ouf mais mais je pars du principe qu'il y'aura pas bcp de tilemap renderers dans une meme scene,
///et que ça sert à rien d'en mettre plusieurs si ils ont les memes sprites.

class TilemapRendererNode : public RendererNode
{
public:
    ~TilemapRendererNode() override;
    bool LoadXmlAttribute(string key, string value) override;
    void Initialize() override;

    Transform TransformTileToScreen(CameraNode& Camera, const int& x, const int& y, const int& PixelsPerTile);
    void Draw(CameraNode& Camera) override;

private :
    void LoadTileSet(path tilesPath);

private:
    TilemapNode* _tilemap = nullptr;

    ///couleur->tile
    std::map<int,AutoTile*> _tiles ;
};


#endif //TESTSFML_TILEMAPRENDERERNODE_H