//
// Created by Nathan on 12/08/2025.
//
#include "Game.h"

#include "../Engine/Nodes/NodeSerialization/SceneLoader.h"
#include "../Engine/Nodes/SceneNodes/Behaviours/linearMovement/LinearRotatorNode.h"
#include "../Engine/Nodes/SceneNodes/Renderers/DotRendererNode.h"
#include "Behaviours/Camera/CameraBehaviourNode.h"
Game::Game()=default;

Game::~Game()
{
    delete sceneRoot;
    sceneRoot = nullptr;
}

void Game::LoadScene()
{
    SceneLoader sceneLoader = SceneLoader();
    sceneRoot=sceneLoader.LoadScene("MainScene.xml");

    CameraNode::Current->renderTarget = &Window;
    cout<<"====\n";
    sceneRoot->PrintTree();
}

void Game::InitGraphics()
{
    spriteManager.LoadAllTexturesInDirectory("Shared");
    spriteManager.LoadAllSpritesInDirectory("");
}

void Game::init()
{
    //window creation
    Window = sf::RenderWindow(
        sf::VideoMode({1920*3/5, 1080*3/5}),
        "My window",
        sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar,
        sf::State::Windowed);
    Window.setVerticalSyncEnabled(true);

    InitGraphics();
    LoadScene();
}

void Game::run()
{

    init();

    rendererManager.InitializeAllRenderers();
    behaviourManager.StartAllBehavioursInOrder();

    cout<<"==== game initialised successfully ! Entering main loop. ===="<<endl;

    // run the program as long as the window is open
    sf::Clock clock = sf::Clock();
    float deltaTime = 1.0f/60.0f;
    while (Window.isOpen())
    {
        try
        {
            HandleWindowEvents();
            behaviourManager.UpdateAllBehavioursInOrder(deltaTime);
            DrawGame();
        }
        catch (std::exception& e)
        {
            std::cerr<<e.what()<<std::endl;
        }

        deltaTime = clock.getElapsedTime().asSeconds();
        clock.restart();
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
    if (!Window.isOpen())
        Window.display();

    Window.clear(sf::Color::White);

    try
    {
        RendererManager::Instance->DrawAllRenderersInOrder(*CameraNode::Current);
    }
    catch (std::exception& e)
    {
        cerr<<e.what()<<std::endl;
    }

    Window.display();
}

