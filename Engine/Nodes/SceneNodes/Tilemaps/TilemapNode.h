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
    bool LoadXmlAttribute(string key, string value) override;

    ///Relative path to png file from Resources/Tilemaps.
    void LoadMap(const path fileName);

    //debug
    void PrintMapInConsole();
    void PrintAllTileTypes();

    //getters
    [[nodiscard]] int GetTile(Vector2u tileId);//todo
    [[nodiscard]] Vector2u GetSize() const;
    [[nodiscard]] const std::map<std::pair<unsigned int,unsigned int>,int>& GetAllTiles() const;

    ///chaque bit represente un voisin de la tile donnee,
    ///en partant de celui en haut à gauche et en suivant le sens de lecture.
    ///le bit est à true si il y'a une tile solide
    ///dans la direction  qu il represente en partant de la tile du milieu, donnee en parametre.
    /// - x -
    /// x x x
    /// x - -
    ///-> 0b01011100
    [[nodiscard]] int8_t GetNeighboursAsBitMask(Vector2u tileID) const; //todo
public:
    float TileSizeCm = 1;;
private:
    std::map<std::pair<unsigned int,unsigned int>,int> tiles ;
    std::unordered_set<int> allTileTypes;
};


#endif //TESTSFML_TILEMAPNODE_H