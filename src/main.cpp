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

  mat4 lookatMatrix = lookAt(30,15,20,1,1,1,0,1,0);
  

  //upload uniforms
  glUniformMatrix4fv(glGetUniformLocation(shaders, "projection"), 1, GL_TRUE, projectionMatrix);
  glUniformMatrix4fv(glGetUniformLocation(shaders, "lookat"), 1, GL_TRUE, lookatMatrix.m);

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
  object.set_model(LoadModelPlus("models/bottle.obj"));

  //load shaders
  shaders = loadShaders("shaders/model.vert","shaders/model.frag");
  if(shaders == 0)
    printf("Error loading shaders.\n");
  else
    glutMainLoop();
}

int main(int argc, char *argv[])
{
  object.set_position(vec3(1,1,1));
  object.set_model(LoadModelPlus("models/bottle.obj"));

  init(argc,argv);
}
