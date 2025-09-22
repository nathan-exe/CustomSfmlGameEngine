//
// Created by Megaport on 08/09/2025.
//

#include "AutoTile.h"

#include <bitset>

#include "../../Nodes/SceneNodes/CameraNode.h"

AutoTile::AutoTile(const std::string& name,const std::string& TexturePath,const std::string& configImagePath,const sf::Vector2i& defaultTile,const int& pixelsPerTile)
{
    this->PixelsPerTile = pixelsPerTile;

    cout<<"-Constructing AutoTile-"<<endl;
    texture = new sf::Texture(TexturePath,false);
    texture->setSmooth(true);

    //sprites
    sf::Image configImage(configImagePath);
    for (unsigned y = 0; y < configImage.getSize().y/3; y++)
    {
        for (unsigned x = 0; x < configImage.getSize().x/3; x++)
        {
            sf::Color color = configImage.getPixel({x*3+1,y*3+1});
            if (color == sf::Color::White)
            {
                int8_t bitmaskYes = 0;
                int8_t bitmaskNo = 0;
                short bit = 0;
                for (int dy = 1; dy >= -1; dy--)
                {
                    for (int dx = 1; dx >= -1; dx--)
                    {
                        if (dx==0 && dy==0) continue;


                        sf::Color neighbourColor = configImage.getPixel({x*3+1+dx,y*3+1+dy});
                        bitmaskYes |= static_cast<int8_t>(neighbourColor == sf::Color::Green) <<bit;
                        bitmaskNo |= static_cast<int8_t>(neighbourColor == sf::Color::Red) <<bit;

                        bit++;
                    }
                }

                //temp
                if (_sprites.contains(std::make_pair(bitmaskYes,bitmaskNo)))
                    continue;

                //create sprite
                sf::IntRect rect;
                rect.position = {
                    (int)(pixelsPerTile*x),
                    (int)(pixelsPerTile*y)};
                rect.size = { pixelsPerTile,pixelsPerTile };
                sf::Sprite sprite(*texture,rect);

                //add sprite to map
                _sprites.insert(
                    std::pair<std::pair<int8_t,int8_t>,sf::Sprite>({
                    std::make_pair(bitmaskYes,bitmaskNo),
                    sprite})
                    );
                cout<<"   key : "<<std::bitset<8>( bitmaskYes)<<" "<<std::bitset<8>( bitmaskNo)<<endl;
                if ( defaultTile == sf::Vector2i(x,y))
                {
                    cout<<"   default tile found at : "<<x<<","<<y<<endl;
                    KeyToDefaultTile = std::make_pair(bitmaskYes,bitmaskNo);
                }
            }
        }
    }

    cout<<"auto tile créée !!!"<<endl;
}

AutoTile::~AutoTile()
{
    cout<<"destroyed autoTile !!!"<<endl;
    delete texture;
    texture = nullptr;
}

const sf::Sprite* AutoTile::GetSprite(const int8_t& neighbours) const
{
    for (auto pair : _sprites)
    {
        //todo : commenter
        auto yesNo = pair.first;
        if (((neighbours & yesNo.first) == yesNo.first )
            && ((~neighbours) & yesNo.second) == yesNo.second)
            return &(_sprites.at(yesNo));
    }

    return &_sprites.at(KeyToDefaultTile);
}
