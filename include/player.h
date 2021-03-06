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

#define MAX_SIZE MAP_SIZE*MAP_SIZE
//cannot use deque or other container because of a retarded bug with deque&opengl libs...
//so must go with an simple array to store the positions instead..

class Player
{
 public:
  Player(int x = 0, int z = 0, Direction direction = UP);
  ~Player();

  void init();
  void reset();
  void update(float delta);
  void render(shader_t shader);

  vec3 get_position() const;
  int  get_size() const;
  bool is_dead() const;
  bool is_inside(const int& x, const int& z) const;
  void increase_size();

 private:
  Object    m_body;
  Direction m_direction;
  vec3 m_startpos;
  bool m_dead;

  vec3 m_nodes[MAX_SIZE];
  int  m_size;

  void move();
};

#endif //PLAYER_
