//
// Created by Nathan on 12/08/2025.
//

#include "Node.h"

Node::Node(const string& name )
{
    Name = name;
    Children = std::unordered_set<Node*>();
    Parent = nullptr;
}

Node::~Node()
{
    //cout << "destroying node "<< Name <<endl;

    auto it = Children.begin();
    while (it != Children.end())
    {
        //cout <<"Destroying child : "<< (*it)->Name << endl;
        delete *it;
        it = Children.erase(it);
    }
}

void Node::AddChild(Node* node)
{
    node->Parent = this;
    Children.insert(node);
}

void Node::RemoveChild(Node* child)
{
    child->Parent = nullptr;
    Children.erase(child);
}

void Node::SetParent(Node* newParent)
{
    if (Parent!=nullptr) Parent->Children.erase(this);
    Parent = newParent;
    Parent->Children.insert(this);
}

int Node::GetChildCount() const
{
    return Children.size();
}

int Node::GetTotalChildCount() const
{
    int count = GetChildCount();
    for (const Node* child : Children)
    {
        count += child->GetTotalChildCount();
    }

    return count;
}

int Node::GetDepth() const
{
    if (Parent == nullptr) return 0;
    return Parent->GetDepth()+1;
}

void Node::IterateThroughAllChildren(void(* callback)(Node*))
{
    callback(this);
    for (Node* child : Children)
    {
        child->IterateThroughAllChildren(callback);
    }
}

void Node::PrintTree()
{
    cout<<"Hierarchy : \n";

    GetRoot()->IterateThroughAllChildren(
        [](Node* n) {
            string s = "";
            int depth = n->GetDepth();
            for (int i = 0; i < depth; i++)
                s+="  ";
            cout<< s << n->Name << "\n";
        } );

    cout.flush();
}

string Node::GetPath() const
{
    const Node* node = this;
    string s = node->Name;
    do
    {
        node=node->Parent;
        if (node!=nullptr) s=node->Name+"/"+s;
    }while (node!=nullptr);
    return s;
}


Node* Node::GetRoot()
{
    if (Parent == nullptr) return this;
    return Parent->GetRoot();
}

Node* Node::FindChild(std::function<bool(Node*)> predicate,bool recursive) const
{
    for (Node*const child : Children)
    {
        if (predicate(child))
            return child;
    }

    if (recursive)
        for (Node*const child : Children)
        {
            Node* result = child->FindChild(predicate,recursive);
            if (result!=nullptr) return result;
        }

    return nullptr;
}

Node* Node::FindChildWithName(string Name, bool recursive) const
{
    return this->FindChild(([&](Node* node)-> bool
    {
        return node->Name == Name;
    } ),recursive);
}

Node* Node::FindChildAtPath(string Path) const
{
    std::stringstream ss(Path);
    string name;
    constexpr char del = '/';

    cout << "\nsearching for child of "<<Name<<" with relative path : "<< Path <<"\n";

    Node* node = const_cast<Node*>(this);
    while (getline(ss, name, del) && node!=nullptr)
    {
        node = node->FindChildWithName(name,true);
        if (node!=nullptr) cout <<"found : "<< node->Name << "\n";

    }
    if (node !=nullptr) cout<<"found node : "<<node->Name<<endl;
    else cout<<"could not find child at path : "<<Path<<"\n"<<endl;

    return node;


}



