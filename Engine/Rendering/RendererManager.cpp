//
// Created by Nathan on 17/08/2025.
//

#include "RendererManager.h"


RendererManager* RendererManager::Instance = nullptr;

RendererManager::RendererManager()
{
    Instance = this;
}

RendererManager::~RendererManager()
{

}

void RendererManager::DrawAllRenderersInOrder(CameraNode& camera) const
{
    //cout<<"renderer count : "<<renderers.size()<<endl;
    //cout<<"window : "<<&camera.renderTarget<<endl;
    //cout<<"camera: "<<&camera<<endl;
    for (RendererNode* renderer : renderers)
    {
        //cout<<"Renderer : "<<renderer->Name<<endl;
        renderer->Draw(camera);
    }
}

void RendererManager::PrintAllRenderersInOrder() const
{
    cout<<"Sprite Renderers : \n";
    for (const RendererNode* renderer : renderers)
        cout<<"node "<<renderer->GetPath() <<" has layer : "<<renderer->layer<<".\n";
    cout.flush();
}

void RendererManager::RegisterRenderer(RendererNode* renderer)
{
    renderers.insert(
        std::upper_bound(
            renderers.begin(),renderers.end(),
                renderer,
                [](const RendererNode* a, const RendererNode* b)
                {
                    return a->layer>b->layer;
                })
            ,renderer);
}

void RendererManager::UnregisterRenderer(RendererNode* renderer)
{
    renderers.erase(std::remove(renderers.begin(), renderers.end(), renderer), renderers.end());
}

void RendererManager::UpdateRendererLayer(RendererNode* renderer)
{

}
