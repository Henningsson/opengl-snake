#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

#define FRAMES_PER_SECOND 60
#define WINDOW_HEIGHT     480
#define WINDOW_WIDTH      640

#define MAP_SIZE 15
#define ELEVATION 25.5

#define near 1.0
#define far 500.0
#define right 0.5
#define left -0.5
#define top 0.5
#define bottom -0.5
static GLfloat  projectionMatrix[16] = {2.0f*near/(right-left), 0.0f, (right+left)/(right-left), 0.0f,
                                    0.0f, 2.0f*near/(top-bottom), (top+bottom)/(top-bottom), 0.0f,
                                    0.0f, 0.0f, -(far + near)/(far - near), -2*far*near/(far - near),
			            0.0f, 0.0f, -1.0f, 0.0f };

typedef GLuint texture_t;
typedef GLuint shader_t;

//global shaders
extern shader_t  objshader; //shader for objects

#endif //COMMON_HEADER_H
