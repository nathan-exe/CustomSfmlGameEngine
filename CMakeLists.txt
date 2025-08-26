cmake_minimum_required(VERSION 4.0)
project(testSFML)

set(CMAKE_CXX_STANDARD 26)
find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)

add_executable(testSFML main.cpp
        Engine/Engine.h
        Engine/Nodes/Node.cpp
        Engine/Nodes/Node.h
        Engine/Nodes/SceneNodes/SceneNode.cpp
        Engine/Nodes/SceneNodes/SceneNode.h
        Engine/Rendering/SpriteManager.cpp
        Engine/Rendering/SpriteManager.h
        Game/Game.cpp
        Game/Game.h
        Engine/Nodes/SceneNodes/Renderers/RendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/RendererNode.h
        Engine/Nodes/SceneNodes/Renderers/SpriteRendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/SpriteRendererNode.h
        Engine/Rendering/RendererManager.cpp
        Engine/Rendering/RendererManager.h
        Engine/Rendering/Rendering.h
        Engine/Nodes/AllNodes.h
        Engine/Nodes/SceneNodes/CameraNode.cpp
        Engine/Nodes/SceneNodes/CameraNode.h
        Engine/Dependencies.h
        Engine/Utils/DataSerializer.cpp
        Engine/Utils/DataSerializer.h
        Engine/Nodes/SceneNodes/Renderers/DotRendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/DotRendererNode.h
        Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.cpp
        Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.h
        Engine/Nodes/SceneNodes/Behaviours/BehaviourManager.cpp
        Engine/Nodes/SceneNodes/Behaviours/BehaviourManager.h


)
target_link_libraries(testSFML PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)
