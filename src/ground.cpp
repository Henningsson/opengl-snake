#include "../include/ground.h"
#include <stdio.h>

Ground::Ground(vec3 position)
{
  GLfloat polygon[12] = {
    -500.f,-500.f,0.0f,
    -500.f,500.f,0.0f,
    500.f,-500.f,0.0f,
    500.f,500.f,0.0f
  };
  GLfloat normals[12] = {
    0.0f, 1.f,0.0f,
    0.0f,1.f,0.0f,
    0.0f,1.f,0.0f,
    0.0f,1.f,0.0f
  };
  GLuint indices[6] = {
    0,1,3,
    0,2,3
  };

  GLfloat texCoords[8] = {
    0,0,
    50,0,
    0,50,
    50,50
  };

  set_model( LoadDataToModel(polygon, normals, texCoords, NULL, indices, 12, 6) );
  set_position(position);
  set_rotation(vec3(1.57079633f,0.0,0.0));
}

Ground::~Ground()
{
}


void Ground::render(shader_t shaders)
{
  printf("whatup\n");
  Object::render(shaders);
}
