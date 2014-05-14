/*
 * Huvudklass för spelet 
 */
#ifndef GAME_H
#define GAME_H

#include "object.h"
#include "common_header.h"
#include "player.h"

class Game
{
 public:
  Game();
  ~Game();

  int init();
  void update(float delta);
  void render();

 private:
  //Objects
  Object m_ground;
  Object m_food;
  Object m_skybox;

  //Player
  Player m_player;
};


#endif //GAME_H
