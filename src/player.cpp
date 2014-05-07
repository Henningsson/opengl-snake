#include "../include/player.h"
#include <cmath>
#include <stdio.h>


Player::Player(int x, int z, Direction direction)
  : m_direction(direction), m_next_direction(direction), m_position(vec3(x,1,z))
{
}

Player::~Player()
{
}

void Player::init()
{
  //init model
  m_body.set_model(LoadModelPlus("models/snake_body.obj"));
  m_body.set_position(m_position);
}



void Player::update(float delta)
{
  const GLfloat SPEED = 0.2f;


  //Handle controls & update direction
  if(keyIsDown('w'))
    m_next_direction = RIGHT;
  else if(keyIsDown('s'))
    m_next_direction = LEFT;
  else if(keyIsDown('a'))
    m_next_direction = UP;
  else if(keyIsDown('d'))
    m_next_direction = DOWN;

  //if we are in the center of a tile, switch direction
  //***** BUG ****
  //skitkonstig bug när man incrementerar positionen med SPEED som gör att det inte blir rätt resultat
  // därav denna konstiga lösning
  if( m_position.x - floor(m_position.x) < 0.1 && m_position.z - floor(m_position.z) < 0.1) 
    {
      m_direction = m_next_direction;
    }

  //Apply direction
  switch(m_direction)
    {
    case UP:
      m_position.z += SPEED;
      break;
    case DOWN:
      m_position.z -= SPEED;
      break;
    case LEFT:
      m_position.x += SPEED;
      break;
    case RIGHT:
      m_position.x -= SPEED;
      break;
    }

  printf("x: %f z: %f \n", m_position.x, m_position.z);

  m_body.set_position(m_position);
}


void Player::render(shader_t shader)
{
  m_body.render(shader);
}


vec3 Player::get_position() const
{
  return m_position;
}
