#include "../include/GL_utilities.h"
#include "../include/loadobj.h"
#include "../include/LoadTGA.h"
#include "../include/VectorUtils3.h"

#include "../include/object.h"
#include "../include/common_header.h"

#include <math.h>
#include <stdio.h>

Object object;
shader_t shaders;

/* display callback */
void display_cb()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  object.render(shaders);

  glutSwapBuffers();
}


/* timer callback */
void timer_cb(int value)
{
  glutPostRedisplay();
  glutTimerFunc(FRAMES_PER_SECOND, &timer_cb, value);
}

/* Initializes a OpenGL window  */
void init(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitContextVersion(3,2);
  glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("opengl-snake");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display_cb);
  glutTimerFunc(FRAMES_PER_SECOND, &timer_cb, 0);
  glClearColor(0.2,0.2,0.6,0);
  
  // GAME INITIALIZATION HERE

  glutMainLoop();
}

int main(int argc, char *argv[])
{
  object.set_model(LoadModelPlus("models/bottle.obj"));

  shaders = loadShaders("shaders/model.vert","shaders/model.frag");

  if(shaders == 0)
    {
      printf("Error loading shaders.\n");
      return -1;
    }

  init(argc,argv);
}
