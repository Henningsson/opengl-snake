/* Klass som representerar spelaren
 * och hanterar kontroller samt rendering
 * av ormen.
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include "common_header.h"

enum Direction
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  };


class Player
{
 public:
  Player(int x = 0, int z = 0, Direction direction = UP);
  ~Player();

  void init();
  void update(float delta);
  void render(shader_t shader);

  vec3 get_position() const;

 private:
  Object    m_body;
  vec3      m_position;
  Direction m_direction;
};

#endif //PLAYER_H
