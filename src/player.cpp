#include "../include/player.h"

Player::Player(int x, int z, Direction direction)
  : m_direction(direction), m_position(vec3(x,1,z))
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
  //Handle controls & update direction
  if(keyIsDown('w'))
    m_direction = RIGHT;
  else if(keyIsDown('s'))
    m_direction = LEFT;
  else if(keyIsDown('a'))
    m_direction = UP;
  else if(keyIsDown('d'))
    m_direction = DOWN;

  //Apply direction
  switch(m_direction)
    {
    case UP:
      m_position.z++;
      break;
    case DOWN:
      m_position.z--;
      break;
    case LEFT:
      m_position.x++;
      break;
    case RIGHT:
      m_position.x--;
      break;
    }

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
