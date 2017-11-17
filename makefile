all:  matrix_math.o Fraction.o
	g++  matrix_math.o Fraction.o -o matrix_math -std=c++11

matrix_math.o: Matrix.h Matrix.cpp matrix_math.cpp complex.h complex.cpp
	g++ -c matrix_math.cpp -std=c++11	

%.o: %.cpp %.h
	g++ -c $< -std=c++11

clean:
	rm -rf ./*.o
