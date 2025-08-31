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
    [[nodiscard]] SceneNode* InstantiateEmptyNode(std::string type);
    [[nodiscard]] SceneNode* LoadNode(xml_node<>* xmlNode);

///relative file path from Resources/Scenes
    [[nodiscard]] SceneNode* LoadScene(const path filepath);
};


#endif //TESTSFML_SCENELOADER_H