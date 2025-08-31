//
// Created by Nathan on 14/08/2025.
//

#ifndef TESTSFML_SPRITEMANAGER_H
#define TESTSFML_SPRITEMANAGER_H
#include <string>
#include <unordered_map>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include<filesystem>
#include <iostream>
#include <ranges>
#include <vector>
#include <SFML/System/Exception.hpp>
#include <fstream>
#include "../../Utils/StringConversions.h"

using namespace std::filesystem;
using std::cout,std::cerr,std::endl;
using std::string;

class SpriteManager
{

public :
    SpriteManager();
    ~SpriteManager();

    void CreateSprite(const string& spriteName, const string& textureToUse, sf::IntRect rect, sf::Vector2f origin = {0,0});

    ///should be called early before loading sprites.
    ///path is relative to 'Resources/Textures'
    void LoadAllTexturesInDirectory(const string& directory,bool recursive =true);
    void LoadSpriteFromFile(path path);
    void LoadAllSpritesInDirectory(const string& directory,bool recursive = true);
    void ClearAllTexturesAndSprites();

    [[nodiscard]] bool HasSprite(const string& spriteName) const;
    [[nodiscard]] const sf::Sprite GetSprite(const string& spriteName) const;
    bool TryGetSprite(string& spriteName, sf::Sprite* p_Sprite) const;

    [[nodiscard]] std::vector<string> GetAllLoadedSpritesNames() const;
    [[nodiscard]] std::vector<string> GetAllLoadedTexturesNames() const;

public :
    static const SpriteManager* Instance;

private :
    std::unordered_map<string,sf::Texture> m_textures;
    std::unordered_map<string,sf::Sprite> m_sprites;
};

#endif //TESTSFML_SPRITEMANAGER_H