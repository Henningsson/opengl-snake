#include "../include/game.h"
#include "../include/LoadTGA.h"
#include "../include/object.h"
#include "../include/MicroGlut.h"

#include <stdlib.h>
#include <time.h>


//textures
texture_t groundtexture;
texture_t skyboxtexture;

//DEFINITION OF GLOBAL SHADERS GOES HERE
shader_t objshader;
shader_t skyboxshader;

Game::Game()
{
}

Game::~Game()
{
}

int Game::init()
{
  //init rand
  srand(time(nullptr));

  //load and compile shaders
  objshader    = loadShaders("shaders/model.vert", "shaders/model.frag");
  skyboxshader = loadShaders("shaders/skybox.vert", "shaders/skybox.frag");
  if(objshader == 0 || skyboxshader == 0)
    return -1;

  //load textures  
  LoadTGATextureSimple("textures/ground.tga", &groundtexture);
  LoadTGATextureSimple("textures/skybox.tga", &skyboxtexture);

  //Initialize the player
  m_player.init();

  //Initialize the food-piece
  m_food.set_position(vec3(3,0,3));
  m_food.set_model(LoadModelPlus("models/food.obj"));
  
  //Initialize the skybox
  m_skybox.set_model(LoadModelPlus("models/skybox.obj"));
  m_skybox.set_texture(skyboxtexture);
  m_skybox.set_position(vec3(0,-10000,0));

  m_level.generate();

  return 0;
}


void Game::update(float delta)
{
  m_player.update(delta);

  if(m_player.get_position().x == m_food.get_position().x && m_player.get_position().z == m_food.get_position().z)
    {
      m_player.increase_size();

      vec3 newPos;
      newPos.x = rand() % MAP_SIZE;
      newPos.z = rand() % MAP_SIZE;

      m_food.set_position(newPos);
    }

}


void Game::render()
{
  vec3 pos = m_player.get_position();
  pos.y = 1.0;
  mat4 lookatMatrix = lookAt( MAP_SIZE/2, MAP_SIZE/1.5, MAP_SIZE+5 ,pos.x,pos.y,pos.z,0,1,0);
  
  //upload uniforms
  glUniformMatrix4fv(glGetUniformLocation(objshader, "projection"), 1, GL_TRUE, projectionMatrix);
  glUniformMatrix4fv(glGetUniformLocation(objshader, "lookat"), 1, GL_TRUE, lookatMatrix.m);

  // DRAW SKYBOX
  // the skybox requires some special
  // attention..
  glDisable(GL_DEPTH_TEST);
  mat4 rot = Rx(0.0f);
  mat4 trans = T(0,0,0);
  mat4 total = Mult(trans,rot);
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, skyboxtexture);
  glUseProgram(skyboxshader); //aktivera shadern
  glUniform1i(glGetUniformLocation(skyboxshader, "texture"), 0);
  glUniformMatrix4fv(glGetUniformLocation(skyboxshader, "transform"), 1, GL_TRUE, total.m); // Upload our matrix
  glUniformMatrix4fv(glGetUniformLocation(skyboxshader, "lookat"), 1, GL_TRUE, lookatMatrix.m); // Upload our matrix
  DrawModel(m_skybox.get_model(), skyboxshader, "in_position", "in_normal", "in_texcoord");
  glEnable(GL_DEPTH_TEST);
  
  m_level.render(objshader);
  m_food.render(objshader);
  m_player.render(objshader);
}
