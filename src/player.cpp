#include "../include/player.h"
#include "../include/LoadTGA.h"

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
}


void Player::render(shader_t shader)
{
  m_body.render(shader);
}


vec3 Player::get_position() const
{
  return m_position;
}
