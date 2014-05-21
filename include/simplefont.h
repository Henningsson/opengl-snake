#ifndef _SIMPLEFONT_
#define _SIMPLEFONT_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __APPLE__
	#include <OpenGL/gl3.h>
	#include "MicroGlut.h"
#else
	#ifdef _WIN32
	    #include <GL/glew.h>
		#include <GL/glut.h>
	 
//	    #include <stdlib.h>
//	    #include <stdio.h>
//	    #include <stddef.h>
//	    #include <string.h>
	#else
		#include <GL/gl.h>
	#endif
#endif
#include <stdlib.h>
#include <string.h>

void sfMakeRasterFont(void);
void sfDrawString(int h, int v, char *s);
void sfSetRasterSize(int h, int v);

#ifdef __cplusplus
}
#endif

#endif
