all: snake

snake:	main.cpp
	 g++ -std=c++0x main.cpp -o snake -lsfml-graphics -lsfml-window -lsfml-system -lGLU

clean: rm snake