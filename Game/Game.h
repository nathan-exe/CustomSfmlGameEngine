//
// Created by Nathan on 12/08/2025.
//

#ifndef TESTSFML_GAME_H
#define TESTSFML_GAME_H

#include "../Engine/Engine.h"
#include "../Engine/Systems/Behaviours/BehaviourManager.h"

class Game
{
public :
  Game();
  ~Game();
  void init();
  void run();

private:
  void HandleWindowEvents();
  void DrawGame();

  void LoadScene();
  void LoadAllGameSprites();

private :
  sf::RenderWindow Window;
  SpriteManager spriteManager;
  RendererManager rendererManager;
  BehaviourManager behaviourManager;
  SceneNode* sceneRoot = nullptr;
  CameraNode* camera = nullptr;
};


#endif //TESTSFML_GAME_H