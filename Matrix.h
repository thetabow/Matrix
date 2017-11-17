/*------------------------------------------------------------------------------

FILE NAME: Matrix.h

DESCRITION: Header file for Matrix class and matrix_ops derived class

PURPOSE: class declarations

USAGE: with matrix_math.cpp

EXAMPLES: 

PARAMETERS: N/A

EXIT CODES: 0 success, otherwise error

COMPILATION: 

NOTES:

MODIFICATION HISTORY: 
-----------------------------------------------------------------------------*/


/*------------------------
goals:


implement polynomial class
eigen values and eigen vectors
complex numbers work if only real part and if only imaginary part



inverse	

crammers rule


------------------------*/
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string.h>

#include "Fraction.h"
#include "complex.h"



/*------------------------------------------------------------------------------
CLASS NAME: Matrix
PURPOSE: input, output, constructors, assignment operator
NOTES: Parent to Matrix_ops class
------------------------------------------------------------------------------*/
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
	Matrix(const Matrix<T>&);
	Matrix& operator = (const Matrix&);
	int rows();
	int columns();
	
	class miss_size_error : public runtime_error 
	{
	public:
		miss_size_error(const string&);
	};
	

	//Alex, here is problem of error throwing
	class det_zero_error : public runtime_error
	{
	public:
		det_zero_error(const string&);
	};
	
};


/*------------------------------------------------------------------------------
CLASS NAME: Matrix_ops
PURPOSE: overload operators to do math on matrices
NOTES: inherits from Matrix class
------------------------------------------------------------------------------*/
template <typename T>
class Matrix_ops : public Matrix<T> 
{

public:
	
	Matrix_ops(int rows = 0, int columns = 0);
	bool same_sizeness(const Matrix_ops&) const;
	bool compatible(const Matrix_ops&) const;
	bool square() const;
	Matrix_ops exclude(int, int) const;
	Matrix_ops operator + (const Matrix_ops&) const;
	Matrix_ops operator - (const Matrix_ops&) const;
	Matrix_ops operator * (const Matrix_ops&) const;
	Matrix_ops operator * (int) const;
	bool operator == (const Matrix_ops&)const;
	Matrix_ops trans() const;
	T det() const;
	Matrix_ops cofactor() const;
	Matrix_ops inv() const;
	Matrix_ops exclude() const;
	Matrix_ops reduceRow() const;

};


#include "Matrix.cpp"
#endif //__MATRIX_H__