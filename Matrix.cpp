#include "Matrix.h"

//constructor
Matrix::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	cols = n_cols;

	array = new int*[rows];

	for(int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
	cout << "Matrix constructor: ";
	cout << rows << " x " << cols << endl;

}

int Matrix::get(int i, int j)
{
	return array[i][j];
}

void Matrix::set(int i, int j, int k)
{
	array[i][j] = k;
}

void Matrix::display()
{
	cout << endl;
	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			cout << setw(4) << get(i,j);
		}
		cout << endl;
	}
	cout << endl;
}

Matrix::~Matrix()
{
	for(int i = 0; i < rows; i++)
		delete[] array[i];
	delete [] array;
}