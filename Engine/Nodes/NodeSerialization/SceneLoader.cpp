//
// Created by Megaport on 29/08/2025.
//

#include "SceneLoader.h"

#include <fstream>

#include "../SceneNodes/Behaviours/BehaviourNode.h"
#include "../SceneNodes/Behaviours/linearMovement/LinearRotatorNode.h"
#include "../SceneNodes/Renderers/DotRendererNode.h"



[[nodiscard]] SceneNode* SceneLoader::LoadScene(const path filepath)
{
    path filePath =  "Ressources\\Scenes" / filepath;

    //file validation
    if (!(exists(filePath) && is_regular_file(filePath)))
        throw std::invalid_argument("File does not exist");
    std::ifstream f(filePath);
    if (!f.is_open()) throw std::invalid_argument("File cannot be opened");

    //read file content
    string fileContents="";
    string s;
    while (std::getline(f, s))
        fileContents+=s;
    const char* constText = fileContents.c_str();
    char* text = const_cast<char*>(constText);
    f.close();

    xml_document<> doc;    // character type defaults to char
    doc.parse<0>(text);    // 0 means default parse flags

    xml_node<> *node = doc.first_node();
    return LoadNode(node);

    return nullptr;
}

// ReSharper disable CppDFAMemoryLeak
[[nodiscard]]SceneNode* SceneLoader::InstantiateEmptyNode(std::string type)
{
    //c'est terrifiant mais je sais pas comment faire autrement

    const string defaultName = "newNode";
    if (0==type.compare("SpriteRendererNode"))
        return new SpriteRendererNode(defaultName,"");
    if (0==type.compare("DotRendererNode"))
        return new DotRendererNode(defaultName,sf::Color::Black);
    if (0==type.compare("SceneNode"))
        return new SceneNode(defaultName);
    if (0==type.compare("LinearRotatorNode"))
        return new LinearRotatorNode(defaultName,0);
    if (0==type.compare("CameraNode"))
        return new CameraNode(defaultName,nullptr);

    throw sf::Exception("unknown node type fond in xml file : "+std::string(type));

}

[[nodiscard]] SceneNode* SceneLoader::LoadNode(xml_node<>* xmlNode)
{
    cout << "loading node : " << xmlNode->name() << endl;

    //instantiate new node
    SceneNode* sceneNode;
    sceneNode = InstantiateEmptyNode(xmlNode->name());

    //load node attributes
    for (xml_attribute<> *attr = xmlNode->first_attribute();
         attr!=nullptr; attr = attr->next_attribute())
    {
        cout<<attr->name()<<" : "<<attr->value();
        bool success = sceneNode->LoadXmlAttribute(attr->name(),attr->value());
        if (!success) cerr<<"unknown attribute : "<<attr->name()<<endl;
    }

    //Load children
    for (xml_node<>* child = xmlNode->first_node();child!=nullptr;child=child->next_sibling())
    {
        sceneNode->AddChild(LoadNode(child));
    }

    return sceneNode;
}
