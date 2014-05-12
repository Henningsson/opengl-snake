#include "../include/player.h"
#include <cmath>

Player::Player(int x, int z, Direction direction)
  : m_direction(direction), m_startpos(vec3(x,0,z))
{
  reset();
}

Player::~Player()
{
}

void Player::init()
{
  //init model
  m_body.set_model(LoadModelPlus("models/snake_body.obj"));
}

void Player::reset()
{
  m_size = 3;

  switch(m_direction)
    {
    case LEFT:
      m_nodes[1] = vec3(m_startpos.x+1,0,m_startpos.z);
      m_nodes[2] = vec3(m_startpos.x+2,0,m_startpos.z);
      break;
    case RIGHT:
      m_nodes[1] = vec3(m_startpos.x-1,0,m_startpos.z);
      m_nodes[2] = vec3(m_startpos.x-22,0,m_startpos.z);
      break;
    case UP:
      m_nodes[1] = vec3(m_startpos.x,0,m_startpos.z+1);
      m_nodes[2] = vec3(m_startpos.x,0,m_startpos.z+2);
      break;
    case DOWN:
      m_nodes[1] = vec3(m_startpos.x,0,m_startpos.z-1);
      m_nodes[2] = vec3(m_startpos.x,0,m_startpos.z-2);
      break;
    }

  m_nodes[0] = vec3(m_startpos.x,0,m_startpos.z);
}

void Player::update(float delta)
{
  //Handle controls & update direction
  if(keyIsDown('w') && m_direction != DOWN )
    m_direction = UP;
  else if(keyIsDown('s') && m_direction != UP)
    m_direction = DOWN;
  else if(keyIsDown('a') && m_direction != RIGHT)
    m_direction = LEFT;
  else if(keyIsDown('d') && m_direction != LEFT)
    m_direction = RIGHT;

  if(delta == 0)
    move();
}

/* Movement is based on FPS, this should
 * be fixed so the game doesnt run at different
 * speeds on different computers..
 */
void Player::move()
{ 
  //copy each node back a step, and insert the new node in the front.
  vec3 buffer[MAXSIZE] = m_nodes;

  for(int i = 0; i < m_size-1; ++i)
    {
      m_nodes[i+1] = buffer[i];
    }

  vec3 node = vec3(0,0,0);
  switch(m_direction)
    {
    case UP:
      node = vec3(m_nodes[0].x, 0, m_nodes[0].z-1);
      break;
    case DOWN:
      node = vec3(m_nodes[0].x, 0, m_nodes[0].z+1);
      break;
    case LEFT:
      node = vec3(m_nodes[0].x-1, 0, m_nodes[0].z);
      break;
    case RIGHT:
      node = vec3(m_nodes[0].x+1, 0, m_nodes[0].z);
      break;
    }

  m_nodes[0] = node;
}

void Player::render(shader_t shader)
{
  for(int i = 0; i < m_size; ++i)
    {
      m_body.set_position(m_nodes[i]);
      m_body.render(shader);
    }
}


vec3 Player::get_position() const
{
  return m_nodes[0];
}

void Player::increase_size()
{
  m_size++;
  m_nodes[m_size-1] = m_nodes[m_size-2];
}
