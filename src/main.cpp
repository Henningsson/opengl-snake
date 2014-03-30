#include <SFML/Window.hpp>
#include "../include/Object.h"
#include <SFML/OpenGL.hpp>

using namespace sf;


int main()
{
  shader_t shader;


  sf::Window app(sf::VideoMode(800,600,32), "Horsnake");

  // Set color and depth clear value
  glClearDepth(1.f);
  glClearColor(0.f, 0.f, 0.f, 0.f);

  // Enable Z-buffer read and write
  glEnable(GL_DEPTH_TEST);
  glDepthMask(GL_TRUE);
  // Setup a perspective projection
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.f, 1.f, 1.f, 500.f);



  Object test;
  test.set_model(LoadModelPlus("models/bottle.obj"));
  shader = loadShaders("shaders/model.vert", "shaders/model.frag");

  while (app.isOpen())
    {
      sf::Event event;
      while (app.pollEvent(event))
	{	  
            if (event.type == sf::Event::Closed)
                app.close();
	}

      glBegin(GL_QUADS);

      test.render(shader);

      glEnd();

      app.display();
    }
}
