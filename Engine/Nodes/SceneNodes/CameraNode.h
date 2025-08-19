//
// Created by Nathan on 19/08/2025.
//

#ifndef TESTSFML_CAMERANODE_H
#define TESTSFML_CAMERANODE_H

#include <SFML/Window/Window.hpp>
#include "SceneNode.h"



class CameraNode : public SceneNode
{
public :
    CameraNode(std::string name,sf::Window* window);
    static CameraNode* Current;

    sf::Transform GetViewMatrix() const;
    float worldHeight = 0;

private :
    sf::Window* window = nullptr;

};


#endif //TESTSFML_CAMERANODE_H