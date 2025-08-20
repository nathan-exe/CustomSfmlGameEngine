//
// Created by Nathan on 17/08/2025.
//

#ifndef TESTSFML_RENDERERMANAGER_H
#define TESTSFML_RENDERERMANAGER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include "../Nodes/SceneNodes/Renderers/RendererNode.h"
#include "../Nodes/SceneNodes/CameraNode.h"


class RendererManager
{
public:
    RendererManager();
    ~RendererManager();
    static RendererManager* Instance;

    void DrawAllRenderersInOrder(CameraNode& camera) const;
    void PrintAllRenderersInOrder() const;

    void RegisterRenderer(RendererNode* renderer);
    void UnregisterRenderer(RendererNode* renderer);
    void UpdateRendererLayer(RendererNode* renderer);

private:
    std::vector<RendererNode*> renderers;

};


#endif //TESTSFML_RENDERERMANAGER_H