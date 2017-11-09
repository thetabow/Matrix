#usage ex make hello

.cpp :
	g++ -o $* $*.cpp -std=c++11

matrix_test: Matrix.o matrix_test.o
	g++ -o $@ $@.o Matrix.o -std=c++11

%.o : %.cpp Matrix.h
	g++ -c $< -std=c++11
