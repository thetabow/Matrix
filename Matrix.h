#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

class Matrix {

private:
	int rows, cols;
	int **array;

public:
	Matrix(int rows, int cols);
	~Matrix();
	int get(int i, int j);
	void set(int i, int j, int k);
	void display();

};

#endif //MATRIX_H
	
