//
// Created by Megaport on 31/08/2025.
//

#ifndef TESTSFML_TILEMAPNODE_H
#define TESTSFML_TILEMAPNODE_H
#include "../SceneNode.h"
#include <map>

using std::filesystem::path;
using sf::Vector2u;

class TilemapNode : public SceneNode
{
public :
    TilemapNode(const string& name = DEFAULT_NODE_NAME ) ;

    ///Relative path to png file from Resources/Tilemaps.
    void LoadMap(const path fileName);
    void PrintMapInConsole();
    void PrintAllTileTypes();

    [[nodiscard]] Vector2u GetSize() const;
    [[nodiscard]] int GetTile(Vector2u tileId);

    bool LoadXmlAttribute(string key, string value) override;

    const std::map<std::pair<unsigned int,unsigned int>,int>& GetAllTiles() const;

public:
    float TileSizeCm = 1;

private:
    std::map<std::pair<unsigned int,unsigned int>,int> tiles ;
    std::unordered_set<int> allTileTypes;
};


#endif //TESTSFML_TILEMAPNODE_H