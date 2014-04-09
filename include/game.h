/*
 * Huvudklass för spelet 
 */
#ifndef GAME_H
#define GAME_H

#include "object.h"
#include "common_header.h"

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
};


#endif //GAME_H
