#include "../include/game.h"

shader_t objshader;

Game::Game()
{
}

Game::~Game()
{
}


int Game::init()
{
  //init food-piece
  m_food.set_position(vec3(1,1,1));
  m_food.set_model(LoadModelPlus("models/food.obj"));

  //load and compile shaders
  objshader = loadShaders("shaders/model.vert", "shaders/model.frag");
  if(objshader == 0)
    return -1;

  
  return 0;
}


void Game::update(float delta)
{

}


void Game::render()
{
  vec3 pos = m_food.get_position();
  mat4 lookatMatrix = lookAt(10,5,2,pos.x,pos.y,pos.z,0,1,0);
  
  //upload uniforms
  glUniformMatrix4fv(glGetUniformLocation(objshader, "projection"), 1, GL_TRUE, projectionMatrix);
  glUniformMatrix4fv(glGetUniformLocation(objshader, "lookat"), 1, GL_TRUE, lookatMatrix.m);

  m_food.render(objshader);
}
