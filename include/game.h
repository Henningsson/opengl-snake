/*
 * Huvudklass för spelet 
 */
#ifndef GAME_H
#define GAME_H

#include "object.h"
#include "common_header.h"
#include "player.h"
#include "level.h"


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
  Object m_food;
  Object m_skybox;

  //Player
  Player m_player;

  //Level
  Level  m_level;
};


#endif //GAME_H
