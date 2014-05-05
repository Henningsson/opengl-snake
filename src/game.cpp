#include "../include/game.h"
#include "../include/LoadTGA.h"

#define MAP_SIZE 5

//textures
texture_t groundtexture;

//DEFINITION OF GLOBAL SHADERS GOES HERE
shader_t objshader;

Game::Game()
{
}

Game::~Game()
{
}

int Game::init()
{
  //Initialize the player
  m_player.init();

  //Initialize the food-piece
  m_food.set_position(vec3(1,1,1));
  m_food.set_model(LoadModelPlus("models/snake_body.obj"));

  //load and compile shaders
  objshader = loadShaders("shaders/model.vert", "shaders/model.frag");
  if(objshader == 0)
    return -1;

  //load textures  
  LoadTGATextureSimple("textures/ground.tga", &groundtexture);

  //Initialize the ground
  GLfloat polygon[12] = {
    0.f,0.f,0.0f,
    MAP_SIZE,0.f,0.0f,
    0.f,0.f,MAP_SIZE,
    MAP_SIZE,0.f,MAP_SIZE
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
    MAP_SIZE,0,
    0,MAP_SIZE,
    MAP_SIZE,MAP_SIZE
  };

  m_ground.set_model(LoadDataToModel(polygon, normals, texCoords, NULL, indices, 12, 6));
  m_ground.set_texture(groundtexture);

  return 0;
}


void Game::update(float delta)
{
  m_player.update(delta);
}


void Game::render()
{
  vec3 pos = m_player.get_position();
  mat4 lookatMatrix = lookAt(10,5,5,pos.x,pos.y,pos.z,0,1,0);
  
  //upload uniforms
  glUniformMatrix4fv(glGetUniformLocation(objshader, "projection"), 1, GL_TRUE, projectionMatrix);
  glUniformMatrix4fv(glGetUniformLocation(objshader, "lookat"), 1, GL_TRUE, lookatMatrix.m);

  //m_food.render(objshader);
  m_ground.render(objshader);

  m_player.render(objshader);
}
