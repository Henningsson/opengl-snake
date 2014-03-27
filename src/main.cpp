#include <SFML/Window.hpp>
#include "../include/Object.h"


using namespace sf;

int main()
{
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

  sf::Clock clock;

  while (app.IsOpened())
    {
      sf::Event Event;
      while (app.GetEvent(Event))
	{
	  // Some code for stopping application on close or when escape is pressed...
	}


      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glTranslatef(0.f, 0.f, -200.f);
      glRotatef(clock.GetElapsedTime() * 50, 1.f, 0.f, 0.f);
      glRotatef(clock.GetElapsedTime() * 30, 0.f, 1.f, 0.f);
      glRotatef(clock.GetElapsedTime() * 90, 0.f, 0.f, 1.f);

      glBegin(GL_QUADS);

      glVertex3f(-50.f, -50.f, -50.f);
      glVertex3f(-50.f,  50.f, -50.f);
      glVertex3f( 50.f,  50.f, -50.f);
      glVertex3f( 50.f, -50.f, -50.f);

      glVertex3f(-50.f, -50.f, 50.f);
      glVertex3f(-50.f,  50.f, 50.f);
      glVertex3f( 50.f,  50.f, 50.f);
      glVertex3f( 50.f, -50.f, 50.f);

      glVertex3f(-50.f, -50.f, -50.f);
      glVertex3f(-50.f,  50.f, -50.f);
      glVertex3f(-50.f,  50.f,  50.f);
      glVertex3f(-50.f, -50.f,  50.f);

      glVertex3f(50.f, -50.f, -50.f);
      glVertex3f(50.f,  50.f, -50.f);
      glVertex3f(50.f,  50.f,  50.f);
      glVertex3f(50.f, -50.f,  50.f);

      glVertex3f(-50.f, -50.f,  50.f);
      glVertex3f(-50.f, -50.f, -50.f);
      glVertex3f( 50.f, -50.f, -50.f);
      glVertex3f( 50.f, -50.f,  50.f);

      glVertex3f(-50.f, 50.f,  50.f);
      glVertex3f(-50.f, 50.f, -50.f);
      glVertex3f( 50.f, 50.f, -50.f);
      glVertex3f( 50.f, 50.f,  50.f);

      glEnd();

      app.Display();
    }
}
