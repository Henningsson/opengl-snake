#include "../include/player.h"
#include "../include/game.h"
#include <cmath>
#include <stdlib.h>


Player::Player(int x, int z, Direction direction)
  : m_direction(direction), m_startpos(vec3(x,0,z)), m_dead(false)
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
  m_body.set_color(vec3(0.65,0.95,1));
}

void Player::reset()
{
  m_dead = false;
  m_size = 3;

  switch(m_direction)
    {
    case LEFT:
      m_nodes[1] = vec3(m_startpos.x+1, 0, m_startpos.z);
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
  if((keyIsDown('w') || keyIsDown('W')) && m_direction != DOWN )
    m_direction = UP;
  else if( (keyIsDown('s') || keyIsDown('S')) && m_direction != UP)
    m_direction = DOWN;
  else if( (keyIsDown('a') || keyIsDown('A')) && m_direction != RIGHT)
    m_direction = LEFT;
  else if( (keyIsDown('d') || keyIsDown('D')) && m_direction != LEFT)
    m_direction = RIGHT;

  if(delta == 0)
    move();

  //check if dead
  for(int i = 1; i < m_size-1; ++i)
    {
      if(m_nodes[0].x == m_nodes[i].x && m_nodes[0].z == m_nodes[i].z)
	m_dead = true;
    }
}

/* Movement is based on FPS, this should
 * be fixed so the game doesnt run at different
 * speeds on different computers..
 */
void Player::move()
{ 
  //copy each node back a step, and insert the new node in the front.
  vec3 buffer[MAX_SIZE] = m_nodes;

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

  //Keep within boundaries
  if(node.x < 0)
    node.x = MAP_SIZE-1;
  else if(node.x > MAP_SIZE-1)
    node.x = 0;
  if(node.z < 0)
    node.z = MAP_SIZE-1;
  else if(node.z > MAP_SIZE-1)
    node.z = 0;

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

int Player::get_size() const
{
  return m_size;
}

bool Player::is_dead() const
{
  return m_dead;
}

bool Player::is_inside(const int& x, const int& z) const
{
  for(int i = 0; i < m_size; ++i)
    {
      if(m_nodes[i].x == x && m_nodes[i].z == z)
	return true;
    }
  return false;
}

void Player::increase_size()
{
  m_size++;
  m_nodes[m_size-1] = m_nodes[m_size-2];
}
