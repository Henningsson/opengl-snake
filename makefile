all: lib snake

lib: src/GL_utilities.c
	gcc -std=c99 -c src/GL_utilities.c src/MicroGlut.c src/loadobj.c src/LoadTGA.c src/VectorUtils3.c -lm -lGL -DGL_GLEXT_PROTOTYPES -w

snake:	src/main.cpp src/object.cpp
	 g++ -std=c++0x src/main.cpp src/object.cpp GL_utilities.o loadobj.o LoadTGA.o MicroGlut.o VectorUtils3.o -o snake -lm -lGL -DGL_GLEXT_PROTOTYPES

clean:
	rm snake
	rm GL_utilities.o
	rm loadobj.o
	rm LoadTGA.o
	rm MicroGlut.o
	rm VectorUtils3.o