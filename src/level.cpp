#include "../include/level.h"
#include <stdlib.h>

Level::Level()
{
}

Level::~Level() 
{
}

void Level::generate()
{
  //Load the model
  m_tile.set_model(LoadModelPlus("models/ground.obj"));
  
  //Generate the level
  for(int x = 0; x < MAP_SIZE; ++x)
    {
      for(int z = 0; z < MAP_SIZE; ++z)
	{
	  m_tiles[x][z] = -ELEVATION; //(static_cast <float> (rand()) / static_cast <float> (RAND_MAX))/3;
	}
    }
}

void Level::render(const shader_t& shaders)
{
  for(int x = 0; x < MAP_SIZE; ++x)
    {
      for(int z = 0; z < MAP_SIZE; ++z)
	{ 
	  m_tile.set_position( vec3( x, m_tiles[x][z], z ) );
	  m_tile.render(shaders);
	}
    }
}

GLfloat Level::get_elevation(const int& x, const int& z)
{
  return m_tiles[x][z];
}
