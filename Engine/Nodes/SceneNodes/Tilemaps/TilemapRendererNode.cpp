//
// Created by Megaport on 31/08/2025.
//

#include "TilemapRendererNode.h"


TilemapRendererNode::~TilemapRendererNode()
{
    //clear sprites ?
}

void TilemapRendererNode::Draw(CameraNode& Camera)
{
    //cout<<"- drawing Tilemap ! - "<<endl;
    for (auto pair : _tilemap->GetAllTiles())
    {
        int x = pair.first.first;
        int y = pair.first.second;
        int tileID = pair.second;

        //if (tileID==-1)continue;

        sf::RectangleShape rectangleShape({static_cast<float>(Camera.PixelsPerUnit),static_cast<float>(Camera.PixelsPerUnit)});
        rectangleShape.setFillColor(sf::Color(tileID));

        Drawable* tile = &rectangleShape;//_tileVisuals.at(tileID);

        sf::Transform texelToLocal = sf::Transform::Identity;
        float invPixelsPerUnits = 1.0f/Camera.PixelsPerUnit;
        texelToLocal.scale({invPixelsPerUnits,-invPixelsPerUnits});

        sf::Transform localToTile = sf::Transform::Identity;
        localToTile.scale({_tilemap->TileSizeCm,_tilemap->TileSizeCm});
        localToTile.translate({static_cast<float>(x),static_cast<float>(y)});

        sf::Transform worldToScreen =  Camera.WorldToScreenMatrix();
        sf::Transform localToScreen = worldToScreen * GetWorldTransform() *localToTile* texelToLocal;
        //cout<<"     x : "<<x<<", y : "<<y<<", tileID : "<<tileID<<endl;
        Camera.renderTarget->draw(*tile,localToScreen);

    }

}

void TilemapRendererNode::Initialize()
{
    RendererNode::Initialize();
    _tilemap = static_cast<TilemapNode*>(Parent);
}

void TilemapRendererNode::LoadTileSet()
{
    //open .tiles file and load config
    //create sprites
}
