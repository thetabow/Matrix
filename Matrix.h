/*------------------------------------------------------------------------------

FILE NAME: Matrix.h

DESCRITION: Header file for Matrix class and matrix_ops derived class

PURPOSE: class declarations

USAGE: idk yet

EXAMPLES: 

PARAMETERS: yup

EXIT CODES: 0 success, otherwise error

COMPILATION: 

NOTES:

MODIFICATION HISTORY: 
-----------------------------------------------------------------------------*/


/*------------------------
goals:

MATRIX FILES A.mtx
		3x4
		1	2	-3	-2
		1	2	3	1
		-2	7	4	-10

input
output
assignment
commands
entries can be polynomials!
add
sub
mult
equal test
transpose
inverse
determinant
crammers rule

------------------------*/
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>

template <typename T>
class Matrix 
{

template <typename B>
friend istream& operator >> (istream& inFile, Matrix<B>& mat);
template <typename B>
friend ostream& operator << (ostream& out, Matrix<B>& mat);


protected:
	int c;
	int r;

	vector<vector<T>> entries;


public:
	
};
#include "Matrix.cpp"

class Matrix_ops : public Matrix
{
public:
	bool same_sizeness(Matrix_ops& const matthew);
}