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
#ifndef __MATRIX_H__
#define __MATRIX_H__
using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

template <typename T>
class Matrix 
{


template <typename B>
friend istream& operator >> (istream& inFile, Matrix<B>& mat);
template <typename B>
friend ostream& operator << (ostream& out, const Matrix<B>& mat);


protected:
	int c;
	int r;

	vector<vector<T>> entries;


public:
	Matrix(int rows = 0, int columns = 0);
	class miss_size_error : public runtime_error 
	{
	public:
		miss_size_error(const string&);
	};
};

/*------------------------------------------------------------------------------
------------------------------------------------------------------------------*/
//template <typename T>
//class Matrix<T>;
template <typename T>
class Matrix_ops : public Matrix<T> 
{

public:
	
	Matrix_ops(int rows = 0, int columns = 0);
	bool same_sizeness(const Matrix_ops&) const;
	bool compatible(const Matrix_ops&) const;
	bool square() const;
	Matrix_ops operator + (const Matrix_ops&) const;
	Matrix_ops operator - (const Matrix_ops&) const;
	Matrix_ops operator * (const Matrix_ops&) const;
	Matrix_ops operator * (int) const;
};


#include "Matrix.cpp"
#endif //__MATRIX_H__