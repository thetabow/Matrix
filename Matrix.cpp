/*--------------------------------------------------------------------------------------------
FUNTION NAME: Matrix.cpp

DESCRIPTION: holds function definitions for Matrix class and matrix_ops derived class

PURPOSE: definition of used class functions

EXAMPLES: 

PARAMETERS:

EXIT CODES:

COMPILATION: 

NOTES:

MODIFICATION HISTORY:

------------------------------------------------------------------------------------------*/

//#include "Matrix.h"

/*------------------------------------------------------------------------------------------
FUNCTION NAME: Matrix overloaded constructor
PURPOSE: resizes matrix and sets all entries to 0
RETURNS: nothing
NOTES:
------------------------------------------------------------------------------------------*/
template <typename T>
Matrix<T>::Matrix(int rows, int columns)
{
	r = rows;
	c = columns;
	entries.resize(r);
	for(int i = 0; i < r; i++)
	{
		entries[i].resize(c);
		for(int j = 0; j < c; j++)
		{
			entries[i][j] = 0;
		}
	}
}

template <typename T>
Matrix_ops<T>::Matrix_ops(int rows, int columns):Matrix<T>(rows, columns)
{

}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: Matrix_ops operator +
PURPOSE: add 2 compatible matrices
RETURNS: Matrix_ops
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::operator+(const Matrix_ops<T>& mattey) const
{
	bool check = this->same_sizeness(mattey);
	if(!check)
		throw typename Matrix<T>::miss_size_error("Cannot add 2 matrices of different sizes\n");

	Matrix_ops<T> sum(this->r,this->c);
	for(int i = 0; i < this->r; i++)
	{
		for(int j = 0; j < this->c; j++)
		{
			sum.entries[i][j] = this->entries[i][j] + mattey.entries[i][j];
		}
	}
	return sum;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: Matrix_ops operator -
PURPOSE: subtract 2 comatible matrices
RETURNS Matrix_ops
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::operator - (const Matrix_ops<T>& mat) const
{
	return *this + -1*mat;
}


/*----------------------------------------------------------------------------------------
FUNCTION NAME: operator *
PURPOSE: multiply 2 compatible matrices
RETURNS: Matrix_ops
NOTES:
----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::operator *(const Matrix_ops<T>& x) const
{
	if(this->compatible(x) == false)
		throw typename Matrix<T>::miss_size_error("Incompatible Matrices\n");

	Matrix_ops<T> product(this->r, x.c);
	for(int i = 0; i < product.r; i++)
	{
		for(int j = 0; j < product.c; j++)
		{
			for(int b = 0; b < this->c; b++)
			{
				product.entries[i][j] += this->entries[i][b]*x.entries[b][j];
			}
		}
	}
	return product;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: * operator
PURPOSE: scalar multiplication
RETUNS: Martix_ops
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::operator *(int scale) const
{
	Matrix_ops<T> scale_up(this->r, this->c);

	for(int i = 0; i < this->r; i ++)
	{
		for(int j = 0; j < this->c; j++)
		{
			scale_up.entries[i][j] *= scale;
		}
	}
	return scale_up;
}
/*-----------------------------------------------------------------------------------------
FUNCTION NAME: same_sizeness
PURPOSE: check if the 2 matrices are the same size, useful for addition and subtraction
RETURNS: bool
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
bool Matrix_ops<T>::same_sizeness(const Matrix_ops<T>& matthew) const
{
	if(this->r == matthew.r && this->c == matthew.c)
		return true;
	return false;
}

/*-----------------------------------------------------------------------------------------
FUNCITON: compatible
PURPOSE: tell whether 2 matrices can be multiplied
RETURNS: bool
NOTES: order matters, left*right is being tested for do ability
-----------------------------------------------------------------------------------------*/
template <typename T>
bool Matrix_ops<T>::compatible(const Matrix_ops<T>& mathew) const
{
	if(this->c == mathew.r)
		return true;
	return false;
}

/*-----------------------------------------------------------------------------------------
FUNCTION: square
PURPOSE: tell if a matrix is square
RETURNS: bool
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
bool Matrix_ops<T>::square() const
{
	if(this->r == this->c)
		return true;
	return false;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: >> operator overload
PURPOSE: input from a file to a matrix
RETURNS: istream&
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
istream& operator >> (istream& inFile, Matrix<T>& mat)
{
	char garbage_x;
	inFile >> mat.r;
	inFile >> garbage_x;
	inFile >> mat.c;
	mat.entries.resize(mat.r);

	for(int i = 0; i < mat.r; i++)
	{
		mat.entries[i].resize(mat.c);
		for(int j = 0; j < mat.c; j++)
		{
			inFile >> mat.entries[i][j];
		}
	}
	return inFile;
}
/*-----------------------------------------------------------------------------------------
FUNCTION NAME: << operator overload
PURPOSE: output a matrix with a little formatting
RETURNS: ostream&
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
ostream& operator << (ostream& out, const Matrix<T>& mat) 
{
	for(int i = 0; i < mat.r; i++)
	{
		for(int j = 0; j < mat.c; j++)
		{
			out << mat.entries[i][j] << ' ' ;
		}
		out << "\n";
	}
	return out;
}




template <typename T>
Matrix<T>::miss_size_error::miss_size_error(const string& error):runtime_error(error)
{

}