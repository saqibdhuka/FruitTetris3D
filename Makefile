

all: main.cpp fruits.cpp grid.cpp 
	g++ -o FruitTetris3D main.cpp fruits.cpp grid.cpp -lGL -lGLEW -lGLU -lglut -lX11 -lm -lrt
clean:
	rm FruitTetris main.o fruits.o grid.o 
