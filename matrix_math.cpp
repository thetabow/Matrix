/*--------------------------------------------------------------------------------------
FILE NAME: matrix_math.cpp

DESCRIPTION: driver program for Matrix class

PURPOSE: demonstrate Matrix class and matrix_ops with command line

USAGE: ./matrix_math followed by parameter 

EXAMPLES: ./matrix_math -h , ./matrix_math -add A B , ./matrix_math -det A

PARAMETERS: -h, -inp, -out, -add, -sub, -mul, -eq, -T, -1, -det, -solve
	    all have other parameters that go with them, see -h command for details

EXIT CODES: 0 success, otherwise failure

COMPILATION:

NOTES:

MODIFICATION HISTORY:


----------------------------------------------------------------------------------------*/
#include "Matrix.h"

int main(int argc, char * argv[])
{
	cout << "Hello\n";
	Matrix<int> mat;
	Matrix<int> matty;
	ifstream inFile;
	inFile.open("A.mtx");
	inFile >> A;
	cout << A;

	inFile.close();


	cout << "Thanks bye\n";
	return 0;
}

