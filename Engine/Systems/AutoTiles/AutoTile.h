//
// Created by Megaport on 08/09/2025.
//

#ifndef TESTSFML_AUTOTILE_H
#define TESTSFML_AUTOTILE_H
#include <map>
#include <string>
#include <unordered_map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>


class AutoTile
{
public :
    AutoTile(const std::string& name,const std::string& TexturePath,const std::string& configImagePath,const sf::Vector2i& defaultTile,const int& pixelsPerTile);
    ~AutoTile();
    [[nodiscard]]const sf::Sprite* GetSprite(const int8_t& neighbours) const;

private :
    sf::Texture* texture;
    std::map<std::pair<int8_t,int8_t>,sf::Sprite> _sprites;
    std::pair<unsigned char,unsigned char> KeyToDefaultTile;

public :
    int PixelsPerTile = 1;

};


#endif //TESTSFML_AUTOTILE_H