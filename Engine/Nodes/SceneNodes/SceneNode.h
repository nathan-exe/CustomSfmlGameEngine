//
// Created by Nathan on 13/08/2025.
//

#ifndef TESTSFML_SCENENODE_H
#define TESTSFML_SCENENODE_H
#include <SFML/Graphics/Transformable.hpp>
#include "../Node.h"

class SceneNode : public Node, public sf::Transformable
{
    public:
    SceneNode(const string& name) ;

public :

};


#endif //TESTSFML_SCENENODE_H