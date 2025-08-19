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
#include <SFML/System/Exception.hpp>
using namespace std::filesystem;
using std::cout,std::cerr,std::endl;
using std::string;

class SpriteManager
{

public :
    SpriteManager();
    ~SpriteManager();

    void LoadAllTexturesInDirectory(const string& directory ); //should be called early
    void CreateSprite(const string& spriteName,const string& textureToUse,sf::IntRect rect);
    [[nodiscard]] bool HasSprite(const string& spriteName) const;
    [[nodiscard]] const sf::Sprite GetSprite(const string& spriteName) const;
    bool TryGetSprite(string& spriteName, sf::Sprite* p_Sprite) const;
    [[nodiscard]] std::vector<string> GetAllLoadedSpritesNames() const;
    [[nodiscard]] std::vector<string> GetAllLoadedTexturesNames() const;
    void ClearAllTexturesAndSprites();

public :
    static const SpriteManager* Instance;

private :
    std::unordered_map<string,sf::Texture> m_textures;
    std::unordered_map<string,sf::Sprite> m_sprites;

    //todo : tester de créer le sprite manager,
    //charger les textures, sauvegarder un pointer vers une texture
    //ou un sprite et détruire le spriteManager pour voir si la desallocation
    //se fait bien automatiquement
};


#endif //TESTSFML_SPRITEMANAGER_H