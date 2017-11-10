all:  matrix_math.o
	g++  matrix_math.o -o matrix_math -std=c++11

matrix_math.o: Matrix.h Matrix.cpp matrix_math.cpp
	g++ -c matrix_math.cpp -std=c++11

%.o: %.cpp %.h
	g++ -c $< -std=c++11

clean:
	rm -rf ./*.o
