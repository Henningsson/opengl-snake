#ifndef OBJECT_H
#define OBJECT_H

#include "GL_utilities.h"
#include "VectorUtils3.h"
#include "loadobj.h"


typedef GLuint texture_t;
typedef GLuint shader_t;

class Object
{
 public:
  Object(vec3 position = vec3(0,0,0), vec3 rotation = vec3(0,0,0), vec3 scale = vec3(1,1,1), vec3 color = vec3(1,0.5,1), Model* model = nullptr);
  virtual ~Object();

  void set_position(const vec3& position);
  void set_rotation(const vec3& rotation);
  void set_scale(const vec3& scale);
  void set_texture(const texture_t& texture);
  void set_color(const vec3& color);
  void set_model(Model* model);

  vec3 get_position() const;
  vec3 get_rotation() const;
  vec3 get_scale() const;
  vec3 get_color() const;
  Model* get_model() const;

  virtual void render(const shader_t& shaders);

 private:
  vec3      m_position;
  vec3      m_rotation;
  vec3      m_scale;
  vec3      m_color;
  Model*    m_model;
  texture_t m_texture;
};

#endif //OBJECT_H
