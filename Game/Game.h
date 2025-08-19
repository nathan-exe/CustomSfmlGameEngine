//
// Created by Nathan on 12/08/2025.
//

#ifndef TESTSFML_GAME_H
#define TESTSFML_GAME_H

#include "../Engine/Engine.h"


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

private :
  sf::RenderWindow Window;
  SpriteManager spriteManager;
  RendererManager rendererManager;
  SceneNode* sceneRoot = nullptr;
};


#endif //TESTSFML_GAME_H