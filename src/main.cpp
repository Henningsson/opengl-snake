#include "../include/GL_utilities.h"
#include "../include/loadobj.h"
#include "../include/LoadTGA.h"
#include "../include/VectorUtils3.h"

#include "../include/game.h"
#include "../include/common_header.h"


Game game;

/* render callback */
void display_cb()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  game.render();

  glutSwapBuffers();
}

/* render timer callback */
void render_cb(int value)
{
  if(value>1)
    value = 0;

  game.update(value);

  glutPostRedisplay();
  glutTimerFunc(FRAMES_PER_SECOND, &render_cb, ++value);
}

/* Initializes a OpenGL window  */
void init(int argc, char *argv[])
{
  initKeymapManager(); //for keyboard input

  glutInit(&argc, argv);
  glutInitContextVersion(3,2);
  glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("opengl-snake");
  glEnable(GL_DEPTH_TEST);
  glutDisplayFunc(display_cb);
  glClearColor(1,1,1,0);
  glutTimerFunc(FRAMES_PER_SECOND, &render_cb, 0);
  
  // GAME INITIALIZATION HERE 
  if( game.init() != 0 )
    printf("error initializing game.\n");
  else
    glutMainLoop();
}

int main(int argc, char *argv[])
{
  init(argc,argv);
}
