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
Author:			Date: 			Version:		Details:
----------------------------------------------------------------------------------------------------------------
Zuriah Quinton  11/7/17			1.0				set up input and output to files
Zuriah Quinton  11/9/17			2.0				addition, subtraction, multiplication
Zuriah Quinton  11/9/17			2.1				size checking and compatibility checking
Zuriah Quinton  11/10/17		2.2				command line arguments compatible for existing operations
Zuriah Quinton  11/10/17		2.3				small fixes to output operator, assignment operator
Zuriah Quinton  11/12/17		3.0				Transpose a matrix function
Zuriah Quinton  11/17/17		3.1				Determinant of a matrix function
Zuriah Quinton  11/17/17		3.1.5			Fix small problems with throwing errors related to incorrect size
Zuriah Quinton  12/03/17		3.2				Inverse of a matrix
Zuriah Quinton  12/03/17		4.0				COMPLEX NUMBERS class created (brought fraction class over from last project)
Zuriah Quinton  12/03/17		4.1				finally got around to crammer's rule
Zuriah Quinton  12/05/17		4.2				simplified how to open the files and get info into them
-----------------------------------------------------------------------------*/


/*------------------------
goals:


implement polynomial class
eigen values and eigen vectors

crammers rule


------------------------*/
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string.h>
#include <string>

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
	
	//using Matrix<T> :: rows;

	Matrix_ops(int rows = 0, int columns = 0);
	int openfile(string);
	bool same_sizeness(const Matrix_ops&) const;
	bool compatible(const Matrix_ops&) const;
	bool square() const;
	Matrix_ops excludeColumn(int) const;
	Matrix_ops excludeRow(int) const;
	Matrix_ops exclude(int, int) const;
	Matrix_ops operator + (const Matrix_ops&) const;
	Matrix_ops operator - (const Matrix_ops&) const;
	Matrix_ops operator * (const Matrix_ops&) const;
	Matrix_ops operator * (int) const;
	bool operator == (const Matrix_ops&)const;
	Matrix_ops trans() const;
	T det() const;
	//T determinant() const;
	Matrix_ops cofactor() const;
	Matrix_ops inv() const;
	Matrix_ops swapRows(int, int);
	Matrix_ops swapColumns(int, int) const;
	Matrix_ops exclude() const;
	Matrix_ops reduceRow() const;
	Matrix_ops solve() const;

};


#include "Matrix.cpp"
#endif //__MATRIX_H__