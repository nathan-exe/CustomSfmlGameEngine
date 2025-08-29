//
// Created by Megaport on 29/08/2025.
//

#include "SceneLoader.h"

#include <fstream>




SceneNode* SceneLoader::LoadScene(const path filepath)
{
    // Define the directory path to list files from
    path filePath =  "Ressources\\Scenes" / filepath;

    if (!(exists(filePath) && is_regular_file(filePath)))
        throw std::invalid_argument("File does not exist");
    std::ifstream f(filePath);
    if (!f.is_open()) throw std::invalid_argument("File cannot be opened");

    string fileContents="";
    string s;
    while (std::getline(f, s))
        fileContents+=s;

    // Close the file
    f.close();

   // cout<<fileContents<<endl;
    const char* constText = fileContents.c_str();
    char* text = const_cast<char*>(constText);

    cout<<"constText : "<<constText<<endl;
    cout<<"text : ";
    cout<<text;
    cout<<endl;
    xml_document<> doc;    // character type defaults to char
    doc.parse<0>(text);    // 0 means default parse flags
    cout<<"doc parsed."<<endl;



    xml_node<> *node = doc.first_node();
    LoadNode(node);

    return nullptr;
}

void SceneLoader::LoadNode(xml_node<>* node)
{
    cout << "Name of node is: " << node->name() << endl;

    //iterate through attributes
    for (xml_attribute<> *attr = node->first_attribute();
         attr!=nullptr; attr = attr->next_attribute())
    {
        cout << attr->name() << " : " << attr->value() << endl;
    }

    //iterate through children
    for (xml_node<>* child = node->first_node();child!=nullptr;child=child->next_sibling())
    {
        LoadNode(child);
    }
}