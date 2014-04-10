#include "../include/object.h"
#include "../include/MicroGlut.h"

Object::Object(vec3 position, vec3 rotation, vec3 scale, Model* model)
  : m_position(position), m_rotation(rotation), m_scale(scale), m_model(model)
{
  
}

Object::~Object()
{
  delete m_model;
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


vec3 Object::get_position() const
{
  return m_position;
}

vec3 Object::get_rotation() const
{
  return m_rotation;
}

vec3 Object::get_scale() const
{
  return m_scale;
}


void Object::render(const shader_t& shaders)
{
  glUseProgram(shaders);

  mat4 rot   = Mult(Mult(Rx(m_rotation.x),Ry(m_rotation.y)), Rz(m_rotation.z));
  mat4 scale = S(m_scale.x,m_scale.y,m_scale.z);
  mat4 trans = T(m_position.x, m_position.y, m_position.z);
  
  mat4 total = Mult(Mult(trans,rot), scale);

  glUniformMatrix4fv(glGetUniformLocation(shaders, "transform"), 1, GL_TRUE, total.m); //Upload transform matrix
  DrawModel(m_model, shaders, "in_position", "in_normal", "in_texcoord");
}
