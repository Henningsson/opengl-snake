#include "../include/Object.h"
#include "../include/MicroGlut.h"

Object::Object(vec3 position, vec3 rotation, vec3 scale, Model* model)
  : m_position(position), m_rotation(rotation), m_scale(scale), m_model(model)
{
  
}

Object::~Object()
{

}


void Object::set_position(const vec3& position)
{
  m_position = position;
}

void Object::set_rotation(const vec3& rotation)
{
  m_rotation = rotation;
}

void Object::set_scale(const vec3& scale)
{
  m_scale = scale;
}

void Object::set_texture(const texture_t& texture)
{
  m_texture = texture;
}

void Object::set_model(Model* model)
{
  m_model = model;
}


void Object::render(const shader_t& shaders)
{
  glUseProgram(shaders);

  mat4 total = T(m_position.x, m_position.y, m_position.z);

  glUniformMatrix4fv(glGetUniformLocation(shaders, "transform"), 1, GL_TRUE, total.m); //Upload transform matrix
  DrawModel(m_model, shaders, "position", "normal", "texcoord");
}
