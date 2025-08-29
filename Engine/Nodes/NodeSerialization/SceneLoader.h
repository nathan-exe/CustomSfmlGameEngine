//
// Created by Megaport on 29/08/2025.
//

#ifndef TESTSFML_SCENELOADER_H
#define TESTSFML_SCENELOADER_H
#include "../AllNodes.h"
#include "rapidxml/rapidxml.hpp"
using namespace rapidxml;

class SceneLoader
{
    public:
    void LoadNode(xml_node<>* node);
///relative file path from Ressources/Scenes
    SceneNode* LoadScene(const path filepath);
};


#endif //TESTSFML_SCENELOADER_H