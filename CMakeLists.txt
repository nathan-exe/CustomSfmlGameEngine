cmake_minimum_required(VERSION 4.0)
project(testSFML)

set(CMAKE_CXX_STANDARD 26)
find_package(SFML COMPONENTS Network Graphics Window Audio System CONFIG REQUIRED)
#-DSFML_DIR:PATH=C:\Users\Megaport\.vcpkg-clion\vcpkg\packages\sfml_x86-mingw-dynamic\share\sfml
add_executable(
        testSFML main.cpp
        Engine/Engine.h
        Engine/Nodes/Node.cpp
        Engine/Nodes/Node.h
        Engine/Nodes/SceneNodes/SceneNode.cpp
        Engine/Nodes/SceneNodes/SceneNode.h
        Engine/Systems/Rendering/SpriteManager.cpp
        Engine/Systems/Rendering/SpriteManager.h
        Game/Game.cpp
        Game/Game.h
        Engine/Nodes/SceneNodes/Renderers/RendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/RendererNode.h
        Engine/Nodes/SceneNodes/Renderers/SpriteRendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/SpriteRendererNode.h
        Engine/Systems/Rendering/RendererManager.cpp
        Engine/Systems/Rendering/RendererManager.h
        Engine/Systems/Rendering/Rendering.h
        Engine/Nodes/AllNodes.h
        Engine/Nodes/SceneNodes/CameraNode.cpp
        Engine/Nodes/SceneNodes/CameraNode.h
        Engine/Utils/StringConversions.cpp
        Engine/Utils/StringConversions.h
        Engine/Nodes/SceneNodes/Renderers/DotRendererNode.cpp
        Engine/Nodes/SceneNodes/Renderers/DotRendererNode.h
        Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.cpp
        Engine/Nodes/SceneNodes/Behaviours/BehaviourNode.h
        Engine/Systems/Behaviours/BehaviourManager.cpp
        Engine/Systems/Behaviours/BehaviourManager.h
        Engine/Nodes/SceneNodes/Behaviours/linearMovement/LinearRotatorNode.cpp
        Engine/Nodes/SceneNodes/Behaviours/linearMovement/LinearRotatorNode.h
        Game/Behaviours/Camera/CameraBehaviourNode.cpp
        Game/Behaviours/Camera/CameraBehaviourNode.h
        Engine/Utils/Math.cpp
        Engine/Utils/Math.h
        Engine/Utils/Utils.h
        Engine/Nodes/NodeSerialization/SceneLoader.cpp
        Engine/Nodes/NodeSerialization/SceneLoader.h
        Engine/Nodes/NodeSerialization/ISerializable.h
        Engine/Libs/rapidxml/rapidxml_utils.hpp
        Engine/Libs/rapidxml/rapidxml_print.hpp
        Engine/Libs/rapidxml/rapidxml_iterators.hpp
        Engine/Nodes/SceneNodes/Tilemaps/TilemapNode.cpp
        Engine/Nodes/SceneNodes/Tilemaps/TilemapNode.h
        Engine/Nodes/SceneNodes/Tilemaps/TilemapRendererNode.cpp
        Engine/Nodes/SceneNodes/Tilemaps/TilemapRendererNode.h
)
target_link_libraries(testSFML PRIVATE SFML::Network SFML::Graphics SFML::Window SFML::Audio SFML::System)
