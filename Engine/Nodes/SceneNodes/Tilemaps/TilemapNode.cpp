//
// Created by Megaport on 31/08/2025.
//

#include "TilemapNode.h"

#include <ranges>

TilemapNode::TilemapNode(const string& name) : SceneNode(name)
{
}

void TilemapNode::LoadMap(const path fileName)
{
    path filePath =  "Resources\\Tilemaps" / fileName;
    cout<<"== loading tile map : "<<filePath<<" =="<<endl;

    sf::Image image = sf::Image(filePath);

    tiles.clear();
    for (uint16_t y = 0; y < image.getSize().y; y++)
    {
        for (uint16_t x = 0; x < image.getSize().x; x++)
        {
            int tile = image.getPixel({x, y}).toInteger();
            tiles.insert(
                {{x,y},
                tile});
            allTileTypes.insert(tile);
        }
    }

    PrintMapInConsole();
    cout<<"Found tiles :\n";
    PrintAllTileTypes();

}

void TilemapNode::PrintMapInConsole()
{
    Vector2u size = GetSize();
    for (int y=0; y<size.y; y++)
    {
        for (int x=0; x<size.x; x++)
        {
            cout<<(tiles.at({x, y}) == -1 ? '-' : '*');
        }
        cout << '\n';
    }
    cout.flush();
}

void TilemapNode::PrintAllTileTypes()
{
    for (int type : allTileTypes)
    {
        cout<<type<<' ';
    }
    cout<<endl;
}

Vector2u TilemapNode::GetSize() const
{
    Vector2u size;
    for (const auto tilePosition : tiles | std::views::keys)
    {
        size.x = std::max(size.x,tilePosition.first);
        size.y = std::max(size.y,tilePosition.second);
    }
    return size;
}

bool TilemapNode::LoadXmlAttribute(string key, string value)
{
    bool success = SceneNode::LoadXmlAttribute(key, value);
    if (!success)
    {
        if ((success = key == "mapPath"))
            LoadMap(value);
        else if ((success = key == "TileSizeCm"))
            TileSizeCm = StringConversions::FloatFromString(value);
    }
    return success;
}

const std::map<std::pair<unsigned int, unsigned int>, int>& TilemapNode::GetAllTiles() const
{
    return tiles;
}
