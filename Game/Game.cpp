//
// Created by Nathan on 12/08/2025.
//
#include "Game.h"

#include "../Engine/Nodes/SceneNodes/Renderers/DotRendererNode.h"
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
    //SceneNode* player = new SceneNode("Player");

    SceneNode* Handle = new SpriteRendererNode("PaperMill","paperMill_Handle");
    sceneRoot->AddChild(Handle);

    SceneNode* RotationOrigin = new SceneNode("RotationOrigin");
    Handle->AddChild(RotationOrigin);
    RotationOrigin->Move(Vector2<float>(0,3));

    DotRendererNode* dot = new DotRendererNode("Dot");
    dot->SetParent(Handle);
    dot->SetWorldTransform(Handle->GetWorldToLocalTransform());

    //for
    //SceneNode* wing = new SpriteRendererNode("wing","paperMill_Wing");
    //wing->SetWorldTransform(RotationOrigin->GetWorldToLocalTransform());
    //RotationOrigin->AddChild(wing);

    //player->AddChild(new SceneNode("Collider"));
    //player->AddChild(new SceneNode("InputManager"));
    //(*player->Children.begin())->AddChild(new SceneNode("RigidBody"));
    //(*player->Children.begin())->AddChild(new SceneNode("PlayerMovement"));
    //player->AddChild(new SpriteRendererNode("SpriteRenderer","player"));

    camera = new CameraNode("Camera",&Window);
    CameraNode::Current = camera;
    camera->worldHeight = 10;
    sceneRoot->AddChild(camera);


    /*for (int i =0;i<10;i++)
    {
        SpriteRendererNode* sr = new SpriteRendererNode("SpriteRenderer_decor_"+std::to_string(i),"test");
        //sr->setPosition({static_cast<float>(i),static_cast<float>(i)});
        sceneRoot->AddChild(sr);
    }*/

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
    spriteManager.CreateSprite("test","tileset_enviro.png",sf::IntRect({0,0},{12,12}));
    spriteManager.CreateSprite("player","tileset_enviro.png",sf::IntRect({0,0},{12,12}));
    spriteManager.CreateSprite("paperMill_Handle","testScan.png",sf::IntRect({50,50},{100,200}),{50,20});
    spriteManager.CreateSprite("paperMill_Wing","testScan.png",sf::IntRect({200,150},{50,100}),{25,0});

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

            //test
            switch (key->scancode)
            {
            case sf::Keyboard::Scancode::A:
                static_cast<SceneNode*>(sceneRoot->FindChildWithName("PaperMill"))->Move(Vector2<float>(-1,0));
                break;
            case sf::Keyboard::Scancode::D:
                 static_cast<SceneNode*>(sceneRoot->FindChildWithName("PaperMill"))->Move(Vector2<float>(1,0));
                break;
            case sf::Keyboard::Scancode::W:
                 static_cast<SceneNode*>(sceneRoot->FindChildWithName("PaperMill"))->Move(Vector2<float>(0,1));
                break;
            case sf::Keyboard::Scancode::S:
                 static_cast<SceneNode*>(sceneRoot->FindChildWithName("PaperMill"))->Move(Vector2<float>(0,-1));
                break;
            default:
                break;
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

