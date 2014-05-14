#ifndef LEVEL_H
#define LEVEL_H

#include "object.h"
#include "common_header.h"

class Level
{
 public:
  Level();
  virtual ~Level();

  void generate();
  void render(const shader_t& shaders);

  GLfloat get_elevation(const int& x, const int& z);

 private:
  Object  m_tile;
  GLfloat m_tiles[MAP_SIZE][MAP_SIZE];
};


#endif //LEVEL_H
