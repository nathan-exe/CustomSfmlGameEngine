//
// Created by Nathan on 12/08/2025.
//
#include "Game.h"

#include "../Engine/Nodes/SceneNodes/Behaviours/linearMovement/LinearRotatorNode.h"
#include "../Engine/Nodes/SceneNodes/Renderers/DotRendererNode.h"
#include "Behaviours/Camera/CameraBehaviour.h"
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

    SceneNode* Handle = new SpriteRendererNode("PaperMill","paperMill_Handle");
    sceneRoot->AddChild(Handle);

    auto* RotationOrigin = new LinearRotatorNode("RotationOrigin",120);
    Handle->AddChild(RotationOrigin);
    RotationOrigin->Move(Vector2<float>(0,3));

    auto dot = new DotRendererNode("Dot", sf::Color::Red);
    dot->SetParent(Handle);
    dot->ResetLocalTransform();

    //for
    int c = 3;
    for (int i =0;i<c;i++)
    {
        SceneNode* wing = new SpriteRendererNode("wing","paperMill_Wing");
        RotationOrigin->AddChild(wing);
        wing->ResetLocalTransform();
        wing->Scale({.85f,.85f});
        wing->Rotate(sf::degrees( 360.0f/(float)c*i));
        //RotationOrigin->Rotate(360.0f/3.0f);
    }

    SceneNode* cameraHolder= new SceneNode("CameraHolder");
    cameraHolder->SetWorldPosition({0,10});


    camera = new CameraNode("Camera",&Window);
    camera->worldHeight = 30;

    sceneRoot->AddChild(cameraHolder);
    cameraHolder->AddChild(camera);
    camera->ResetLocalTransform();


    camera->AddChild(new CameraBehaviour("cameraBehaviour"));

    DotRendererNode* dot_cam = new DotRendererNode("Dot", sf::Color::Green);
    dot_cam->SetParent(camera);
    dot_cam->ResetLocalTransform();

    sceneRoot->PrintTree();
}

void Game::LoadAllGameSprites()
{
    spriteManager.LoadAllTexturesInDirectory("Shared");
    spriteManager.CreateSprite("test","tileset_enviro.png",sf::IntRect({0,0},{12,12}));
    spriteManager.CreateSprite("player","tileset_enviro.png",sf::IntRect({0,0},{12,12}));
    spriteManager.CreateSprite("paperMill_Handle","testScan.png",sf::IntRect({50,50},{100,200}),{50,20});
    spriteManager.CreateSprite("paperMill_Wing","testScan.png",sf::IntRect({200,150},{50,100}),{25,0});
}

void Game::init()
{
    //window creation
    Window = sf::RenderWindow(
        sf::VideoMode({1920*4/5, 1080*4/5}),
        "My window",
        sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar,
        sf::State::Windowed);

    Window.setVerticalSyncEnabled(true);

    LoadAllGameSprites();
    LoadScene();

}

void Game::run()
{
    init();

    behaviourManager.StartAllBehavioursInOrder();

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
        catch (sf::Exception e)
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
    Window.clear(sf::Color::White);

    try
    {
        RendererManager::Instance->DrawAllRenderersInOrder(*CameraNode::Current);
    }
    catch (sf::Exception e)
    {
        cerr<<e.what()<<std::endl;
    }

    Window.display();
}

