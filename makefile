all: lib snake

lib: src/GL_utilities.c
	gcc -std=c99 -c src/GL_utilities.c src/MicroGlut.c src/loadobj.c src/LoadTGA.c src/VectorUtils3.c -lm -lGL -DGL_GLEXT_PROTOTYPES

snake:	src/main.cpp src/Object.cpp
	 g++ -std=c++0x src/main.cpp src/Object.cpp GL_utilities.o loadobj.o LoadTGA.o MicroGlut.o VectorUtils3.o -o snake -lsfml-graphics -lsfml-window -lsfml-system -lGL -lm -DGL_GLEXT_PROTOTYPES -lGLU

clean:
	rm snake
	rm lib