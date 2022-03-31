main: main.o funcs.o 3d-space.o
	g++ -o main main.o funcs.o 3d-space.o

tests: tests.o funcs.o 3d-space.o
	g++ -o tests tests.o funcs.o 3d-space.o

funcs.o: funcs.cpp funcs.h

3d-space.o: 3d-space.cpp 3d-space.h coord3d.h

main.o: main.cpp funcs.h coord3d.h 3d-space.h

tests.o: tests.cpp doctest.h funcs.h coord3d.h

clean:
	rm -f main.o funcs.o tests.o
