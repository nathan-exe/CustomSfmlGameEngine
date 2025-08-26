//
// Created by Nathan on 14/08/2025.
//

#include "SpriteManager.h"



const  SpriteManager* SpriteManager ::Instance = nullptr;

SpriteManager::SpriteManager()
{
    //Singleton
    if (SpriteManager::Instance!=nullptr)
    {
        cerr<<" y'a déjà un sprite manager !!!!";
        delete(Instance);
    }
    SpriteManager::Instance = this;

}

SpriteManager::~SpriteManager()
{
    ClearAllTexturesAndSprites();
}

void SpriteManager::LoadAllTexturesInDirectory(const string& directory)
{
    cout<<(SpriteManager::Instance==nullptr);
    // Define the directory path to list files from
    const path basePath = "Ressources\\Textures";

    path directorypath = basePath/directory;

    // To check if the directory exists or not
    if (exists(directorypath) && is_directory(directorypath)){

        // Loop through each item (file or subdirectory) in
        // the directory
        for (const auto& entry : directory_iterator(directorypath))
        {
            // Output the path of the file or subdirectory
            cout << "File path : " << entry.path() << "\n";
            cout << "File name : " << entry.path().filename().string() << "\n";

            //save the texture to the texture map
            m_textures[entry.path().filename().string()] =
                sf::Texture(
                    entry.path(),
                    true);
            m_textures[entry.path().filename().string()].setSmooth(true);
        }

        cout.flush();
    }
    else {
        // Handle the case where the directory doesn't exist
        cerr << "Directory not found." << endl;
    }


}

void SpriteManager::CreateSprite(const string& spriteName, const string& textureToUse, sf::IntRect rect, sf::Vector2f origin)
{
    if (m_textures.contains(textureToUse))
    {
        if (m_sprites.contains(spriteName))
            throw sf::Exception("sprite with name '" + spriteName + "' Already exists !");

        auto sprite = sf::Sprite(m_textures[textureToUse],rect);
        sprite.setOrigin({origin.x,rect.size.y-origin.y});


        m_sprites.insert({
                spriteName,
                sprite
        }) ;

    }else
    {
        throw sf::Exception("No loaded texture with name " + spriteName);
    }
}

bool SpriteManager::HasSprite(const string& spriteName) const
{
    return m_sprites.contains(spriteName);
}

const sf::Sprite SpriteManager::GetSprite(const string& spriteName) const
{
    if (m_sprites.contains(spriteName))
    {
        return (m_sprites.at(spriteName));
    }
    throw sf::Exception("sprite with name " + spriteName+" does not exist.");
}

bool SpriteManager::TryGetSprite(string& spriteName, sf::Sprite* p_Sprite) const
{
    bool found = false;
    if ((found = m_sprites.contains(spriteName)))
    {
        *p_Sprite = (m_sprites.at(spriteName));
    }
    return found;
}

std::vector<string> SpriteManager::GetAllLoadedSpritesNames() const
{
    std::vector<string> names;
    for (const auto& name : m_sprites | std::views::keys) // std::views::keys(m_sprites)
    {
        names.push_back(name);
    }
    return names;
}


std::vector<string> SpriteManager::GetAllLoadedTexturesNames() const
{
    std::vector<string> names;
    for (const auto& name : m_textures | std::views::keys) // std::views::keys(m_sprites)
    {
        names.push_back(name);
    }
    return names;
}

void SpriteManager::ClearAllTexturesAndSprites()
{
    m_sprites.clear();
    m_textures.clear();
}
