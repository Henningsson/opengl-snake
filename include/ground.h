/* Objekt som representerar marken, eller  *
 * själva spelplanen.                      */
#ifndef GROUND_H
#define GROUND_H

#include "object.h"
#include "common_header.h"

class Ground : private Object
{
 public:
  Ground(vec3 position = vec3(0,0,0));
  virtual ~Ground();


  void render(shader_t shaders);
 private:
};

#endif //GROUND_H
