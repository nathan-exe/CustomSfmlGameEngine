//
// Created by Megaport on 31/08/2025.
//

#include "TilemapRendererNode.h"

#include <bitset>

#include "../../../Systems/AutoTiles/AutoTile.h"


TilemapRendererNode::~TilemapRendererNode()
{
    for (auto& tile : _tiles)
    {
        delete tile.second;
        tile.second = nullptr;
    }
}

bool TilemapRendererNode::LoadXmlAttribute(string key, string value)
{
    bool result = SceneNode::LoadXmlAttribute(key, value);
    if (!result)
    {
        if ((result = 0==key.compare("tilesPath")))
        {
            LoadTileSet(value);
        }
    }
    return result ;
}

void TilemapRendererNode::Initialize()
{
    RendererNode::Initialize();
    _tilemap = static_cast<TilemapNode*>(Parent);
}

void TilemapRendererNode::LoadTileSet(path tilesPath)
{
    //todo :
    //  open .tiles file and load config
    //  with sprite manager, try to create sprites with name :
    //  tileSetID+bitmaskAND+bitmaskNOT
    cout<<"about to load tiles at : "<<tilesPath<<endl;
    cout<< std::filesystem::exists(tilesPath)<<endl;
    std::ifstream file{tilesPath};
    file.ignore(3);//pour enlever le byte order mark "ï»¿"
    if (!file.is_open())
        throw sf::Exception("Failed to open file: " + tilesPath.string());

    try
    {
        string line = "";
        while (getline(file, line) && line.compare("- AutoTile -")==0)
        {
            //file read
            getline(file, line);//color
            int color = StringConversions::IntFromString(line.substr(12,8));

            getline(file, line);//null or texture name
            if (line.compare("null")==0)
                continue;
            string autoTileTexturePath = line.substr(10);

            getline(file, line);//pixels per Tile
            int pixelsPerTile = StringConversions::IntFromString(line.substr(18));

            getline(file, line);//autoTile config image name
            string autoTileConfigImagePath = line.substr(18);

            getline(file, line);//default tile
            sf::Vector2i defaultTile = {
                StringConversions::IntFromString(line.substr(15,1)),
                StringConversions::IntFromString(line.substr(17,1))
            };

            //tile instantiation
            string AutoTileName=autoTileTexturePath+'_'+autoTileConfigImagePath;

            _tiles.insert({
                color,
                new AutoTile(AutoTileName,
                autoTileTexturePath,
                autoTileConfigImagePath,
                defaultTile,
                pixelsPerTile)
            });
        }
    }catch (...)
    {
        std::cout<<"probleme avec l'autotile !!"<<endl;
    }

    // Close the file
    file.close();

    cout<<"succesfully loaded tileset at path : "<<tilesPath<<endl;
    cout<<"all tiles : "<<endl;
    for (auto tile : _tiles)
    {
        cout<<"   key : "<<tile.first<<endl;
    }
    cout<<endl;
}

Transform TilemapRendererNode::TransformTileToScreen(CameraNode& Camera, const int& x, const int& y, const int& PixelsPerTile)
{
    sf::Transform texelToLocal = sf::Transform::Identity;
    float invPixelsPerUnits = 1.0f/PixelsPerTile;
    texelToLocal.scale({invPixelsPerUnits,-invPixelsPerUnits});

    sf::Transform localToTile = sf::Transform::Identity;
    localToTile.scale({_tilemap->TileSizeCm,_tilemap->TileSizeCm});
    localToTile.translate({static_cast<float>(x),static_cast<float>(y)});

    sf::Transform worldToScreen =  Camera.WorldToScreenMatrix();
    sf::Transform texelToScreen = worldToScreen * GetWorldTransform() *localToTile* texelToLocal;
    return texelToScreen;
}

void TilemapRendererNode::Draw(CameraNode& Camera)
{
    sf::Font font("Resources//Fonts//NaruMonoDemoRegular-R92j3.ttf");
    sf::Text text(font); // a font is required to make a text object
    text.setCharacterSize(10); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setOrigin({-25,-25});
    //for each tile in the tilemap
    for (auto pair_Position_TileID : _tilemap->GetAllTiles())
    {
        unsigned x = pair_Position_TileID.first.first;
        unsigned y = pair_Position_TileID.first.second;
        int tileID = pair_Position_TileID.second;

        //cout<<"clé : "<<tileID<<endl;

        if (_tiles.contains(tileID))
        {
            //cout<<"la clé existe !!!!"<<endl;

            //find wich tile to draw depending on neighbours (auto tile)
            int8_t neighbours = _tilemap->GetNeighboursAsBitMask({x,y});
            //cout<<"neighbours : "<<std::bitset<8>(neighbours)<<endl;

            const sf::Sprite* sprite = _tiles.at(tileID)->GetSprite(neighbours);

            string s = std::bitset< 3 >( neighbours ).to_string() + '\n'
            +std::bitset< 1 >( neighbours>>3 ).to_string()+'x'+std::bitset< 1 >( neighbours>>5 ).to_string()+ '\n'
            +std::bitset< 3 >( neighbours >>6).to_string()
            ;
            text.setString(s);

            //temp
            //sf::RectangleShape rectangleShape({static_cast<float>(Camera.PixelsPerUnit),static_cast<float>(Camera.PixelsPerUnit)});
            //rectangleShape.setFillColor(sf::Color::Red);
            //Drawable* tile = &rectangleShape;//_tiles.at(tileID);

            //transform tile to screen
            Transform texelToScreen = TransformTileToScreen(Camera, x, y,  _tiles.at(tileID)->PixelsPerTile);

            //draw tile
            Camera.renderTarget->draw(*sprite,texelToScreen);
            Camera.renderTarget->draw(text,texelToScreen);
        }
    }
}