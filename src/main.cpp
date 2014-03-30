#include "../include/GL_utilities.h"
#include "../include/loadobj.h"
#include "../include/LoadTGA.h"
#include "../include/VectorUtils3.h"

#include "../include/object.h"
#include "../include/common_header.h"

#include <math.h>

/* display callback */
void display_cb()
{
  
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
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("opengl-snake");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display_cb);
  glutTimerFunc(FRAMES_PER_SECOND, &timer_cb, 0);
  
  // GAME INITIALIZATION HERE

  glutMainLoop();
}

int main(int argc, char *argv[])
{
  init(argc,argv);
}
