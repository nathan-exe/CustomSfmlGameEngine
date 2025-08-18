//
// Created by Nathan on 12/08/2025.
//
#include "Game.h"

#include "../Engine/Nodes/SceneNodes/SceneNode.h"
#include "../Engine/Nodes/SceneNodes/Renderers/SpriteRendererNode.h"
#include "../Engine/Rendering/RendererManager.h"
#include "../Engine/Rendering/SpriteManager.h"

Game::Game()=default;

Game::~Game()
{
    delete sceneRoot;
    sceneRoot = nullptr;
}

void Game::LoadScene()
{
    //scene hierarchy
    sceneRoot = new SceneNode("SceneRoot");
    SceneNode* player = new SceneNode("Player");
    sceneRoot->AddChild(player);
    player->AddChild(new SceneNode("Collider"));
    player->AddChild(new SceneNode("InputManager"));
    (*player->Children.begin())->AddChild(new SceneNode("RigidBody"));
    (*player->Children.begin())->AddChild(new SceneNode("PlayerMovement"));
    player->AddChild(new SpriteRendererNode("SpriteRenderer","player"));

    for (int i =0;i<10;i++)
    {
        SpriteRendererNode* sr = new SpriteRendererNode("SpriteRenderer_decor_"+std::to_string(i),"test");
        sr->setPosition({static_cast<float>(i),static_cast<float>(i)});
        sceneRoot->AddChild(sr);
    }

    sceneRoot->PrintTree();
}

void Game::init()
{
    //window creation
    Window = sf::RenderWindow(
        sf::VideoMode({800, 600}),
        "My window",
        sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar,
        sf::State::Windowed);

    Window.setVerticalSyncEnabled(true);

    //sprite manager
    //spriteManager = SpriteManager();
    spriteManager.LoadAllTexturesInDirectory("Shared");
    spriteManager.CreateSprite("test","tileset_enviro.png",sf::IntRect({0,0},{16,16}));
    spriteManager.CreateSprite("player","tileset_enviro.png",sf::IntRect({16,16},{16,16}));

    //renderer manager
    //rendererManager = RendererManager();

    LoadScene();

    //rendererManager.PrintAllRenderersInOrder();
}

void Game::run()
{
    init();

    // run the program as long as the window is open
    while (Window.isOpen())
    {
        try
        {
            HandleWindowEvents();
            DrawGame();
        }catch (sf::Exception e)
        {
            std::cerr<<e.what()<<std::endl;
        }

    }

}

void Game::HandleWindowEvents()
{
    // check all the window's events that were triggered since the last iteration of the loop
    while (const std::optional<sf::Event> event = Window.pollEvent())
    {
        // "close requested" event: we close the window
        if (event->is<sf::Event::Closed>())
            Window.close();
        else if (const auto* key = event->getIf<sf::Event::KeyPressed>())
        {
            if (key->scancode == sf::Keyboard::Scancode::Escape)
            {
                Window.close();
            }
        }
    }
}

void Game::DrawGame()
{
    Window.clear(sf::Color::Black);

    RendererManager::Instance->DrawAllRenderersInOrder(Window);

    Window.display();
}

