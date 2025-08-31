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

void SpriteManager::LoadAllTexturesInDirectory(const string& directory,bool recursive)
{
    // Define the directory path to list files from
    const path basePath = "Resources\\Textures";
    path directorypath = basePath/directory;

    cout << "working directory : "<<std::filesystem::current_path()<<endl;
    cout<<"attempting to load textures at path : "<<directorypath<<endl;
    // To check if the directory exists or not
    if (exists(directorypath) && is_directory(directorypath)){

        // Loop through each item (file or subdirectory) in
        // the directory
        for (const auto& entry : directory_iterator(directorypath))
        {

            if (recursive && entry.is_directory())
            {
                cout << "Found subDirectory : " << entry.path() << "\n";
                LoadAllSpritesInDirectory(entry.path().string(), recursive);
            }
            else if (entry.path().extension() == ".png")
            {
                // Output the path of the file or subdirectory
                cout << "File path : " << entry.path() << endl;
                cout << "File name : " << entry.path().filename().string() << endl;
                cout << "File stem : " << entry.path().stem().string() << endl;

                //save the texture to the texture map
                m_textures[entry.path().stem().string()] =
                    sf::Texture(
                        entry.path(),
                        true);
                m_textures[entry.path().stem().string()].setSmooth(true);
            }
        }

        cout.flush();
    }
    else {
        // Handle the case where the directory doesn't exist
        cerr << "Texture directory '"<<directorypath<<"' not found." << endl;
    }
}

void SpriteManager::LoadSpriteFromFile(path path)
{
    cout<<"about to load sprite at : "<<path<<endl;
    std::ifstream file(path);
    if (!file.is_open())
        throw sf::Exception("Failed to open file: " + path.string());

    try
    {
        string line;

        //texture path
        getline(file, line);

        string texture = line.substr(4, line.size()-5);

        //rect
        getline(file, line);
        line = line.substr(7);
        char* characters = const_cast<char*> (line.c_str());
        char del = ',';

        sf::Rect<int> rect;
        rect.position.x = StringConversions::FloatFromString(strtok(characters,&del));
        rect.position.y = StringConversions::FloatFromString(strtok(NULL,&del));
        rect.size.x = StringConversions::FloatFromString(strtok(NULL,&del));
        rect.size.y = StringConversions::FloatFromString(strtok(NULL,&del));

        //origin
        getline(file, line);
        line = line.substr(9);
        characters = const_cast<char*>(line.c_str());
        sf::Vector2f origin;
        origin.x = StringConversions::FloatFromString(strtok(characters,&del));
        origin.y = StringConversions::FloatFromString(strtok(NULL,&del));

        //spritename
        string spritename = path.stem().string();

        cout<<"   spritename name : "<<spritename<<endl;
        cout<<"   texture name : "<<texture<<endl;


        //instantiate sprite
        CreateSprite(spritename,texture,rect,origin);
    }catch (int e)
    {
        cerr<<e;
    }

    // Close the file
    file.close();
}

void SpriteManager::LoadAllSpritesInDirectory(const string& directory,bool recursive)
{
    // Define the directory path to list files from
    const path basePath = "Resources\\Sprites";
    path directorypath ;
    if (! directory.starts_with(basePath.string()))
        directorypath = basePath;
    if (!directory.empty()) directorypath = directorypath/ directory;

    cout<<"attempting to load sprites at path : "<<directorypath<<endl;
    // To check if the directory exists or not
    if (exists(directorypath) && is_directory(directorypath)){

        // Loop through each item (file or subdirectory) in
        // the directory
        for (const auto& entry : directory_iterator(directorypath))
        {
            if (recursive && entry.is_directory())
            {
                cout << "Found subDirectory : " << entry.path() << "\n";
                LoadAllSpritesInDirectory(entry.path().string(), recursive);//au secours
            }
            else if (entry.path().extension() == ".sprt")
            {
                // Output the path of the file or subdirectory
                cout << "sprite path : " << entry.path() << "\n";
                cout.flush();
                //path path = entry.path();

                LoadSpriteFromFile(entry.path());
            }/*else
            {
                cout << "File path : " << entry.path() << "\n";
                cout << "File name : " << entry.path().filename().string() << "\n";
                cout << "File extension : " << entry.path().extension().string() << "\n";
            }*/
        }

        cout.flush();
    }
    else {
        // Handle the case where the directory doesn't exist
        cerr << "Sprite directory '"<<directorypath<<"' not found." << endl;
        throw sf::Exception("Sprite directory '"+directorypath.string()+"' not found.");
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
        cerr<<"No loaded texture with name " + textureToUse;
        throw sf::Exception("No loaded texture with name " + textureToUse);
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
