//
// Created by Nathan on 12/08/2025.
//

#ifndef TESTSFML_NODE_H
#define TESTSFML_NODE_H

#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <functional>
#include <sstream>

using std::string, std::cout,std::endl;
const string DEFAULT_NODE_NAME = "newNode";

class Node
{
public :
    Node(const std::string& name = DEFAULT_NODE_NAME);
    virtual ~Node();

    void AddChild(Node* node);
    void RemoveChild(Node* child);
    void SetParent(Node* newParent);

    Node* GetRoot();
    Node* FindChild(std::function<bool( Node*)> predicate,bool recursive = false) const;
    Node* FindChildWithName(string Name,bool recursive = false) const;
    Node* FindChildAtPath(string Path) const;

    int GetChildCount() const;
    int GetTotalChildCount() const;
    int GetDepth() const;

    void IterateThroughAllChildren(void (*callback)(Node*));

    void PrintTree();
    string GetPath() const;

public :
    Node* Parent;
    std::unordered_set<Node*> Children;
    std::string Name;

};


#endif //TESTSFML_NODE_H