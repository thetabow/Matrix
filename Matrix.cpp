/*--------------------------------------------------------------------------------------------

FILE NAME: Matrix.cpp

DESCRIPTION: holds function definitions for Matrix class and matrix_ops derived class

PURPOSE: definition of used class functions

USAGE: with matrix.h and matrix_math.cpp

EXAMPLES: N/A

PARAMETERS: N/A

EXIT CODES:

COMPILATION: g++

NOTES: templated class

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

/*----------------------------------------------------------------------------------------
FUNCTION NAME: matrix copy constructor
PURPOSE: initializes a matrix to the contents of another
RETURNS: nothing
NOTES:
----------------------------------------------------------------------------------------*/
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& martianMatt)
{
	*this = martianMatt;
}

/*----------------------------------------------------------------------------------------
FUNCTION NAME: operator = 
PURPOSE: assign one matrix contents to this one
RETURNS: Matrix<T>&
NOTES:
----------------------------------------------------------------------------------------*/
template <typename T>
Matrix<T>& Matrix<T>::operator = (const Matrix<T>& mattSmith)
{
	r = mattSmith.r;
	c = mattSmith.c;
	entries.resize(mattSmith.r);
	for(int i = 0; i < r; i++)
	{
		entries[i].resize(mattSmith.c);
		for(int j = 0; j < c; j++)
		{
			entries[i][j] = mattSmith.entries[i][j];
		}
	}
	return *this;
}


template <typename T>
Matrix_ops<T>::Matrix_ops(int rows, int columns):Matrix<T>(rows, columns)
{	}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: Matrix_ops operator +
PURPOSE: add 2 compatible matrices
RETURNS: Matrix_ops
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::operator+(const Matrix_ops<T>& mattey) const
{
	if( !(this->same_sizeness(mattey)) )
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
	return *this + mat*-1;
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

/*----------------------------------------------------------------------------------------
FUNCITON NAME: operator ==
PURPOSE: test if 2 matrices are the same
RETURNS: bool
NOTES:
----------------------------------------------------------------------------------------*/
template <typename T>
bool Matrix_ops<T>::operator ==(const Matrix_ops<T>& mattDamon) const
{
	if(!(this->same_sizeness(mattDamon)))
		return false;
	for(int i = 0; i < mattDamon.r; i++)
	{
		for(int j = 0; j < mattDamon.c; j++)
		{
			if(this->entries[i][j] != mattDamon.entries[i][j])
				return false;
		}
	}
	return true;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: reduceRow()
PURPOSE: return the reduced matrix (maybe just changes this matrix to the reduced one????)
RETURNS: Matrix_ops<T>
NOTES: 
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::reduceRow() const
{
	float x = 1;
	Matrix_ops<T> A(*this);
	int a = 1;
	bool first = true;
	int columnNumber;
	T multiple;
	T doodad;
	for(int rowNumber = 0; rowNumber < A.r; rowNumber++)
	{
		for(int rowStart = rowNumber; rowStart < A.r; rowStart++)
		{
			if(first)
			{
				cout << "salty salty tears\n";
				multiple = A.entries[rowNumber][rowNumber];
				for(columnNumber = 0; columnNumber < A.c; columnNumber++)
				{
					A.entries[rowNumber][columnNumber] /= multiple;
				}
			}
			else{
				doodad = A.entries[rowStart][rowNumber];
				for(columnNumber = 0; columnNumber < A.c; columnNumber++)
				{
					A.entries[rowStart][columnNumber] -= A.entries[rowNumber][columnNumber] * doodad;
				}
			}
			first = false;
		}
		first = true;
	}
	return A;
	
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: exclude()
PURPOSE: return a matrix that excludes a row and a column
RETURNS: matrix_ops
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::exclude(int row, int column) const
{
	Matrix_ops<T> legion((this->r)-1, (this->c)-1);

	int columnMod = 0, rowMod = 0;

	for(int i = 0; i < this->r; i++)
	{
		for(int j = 0; j < this->c; j++)
		{
			if(i == row)
				rowMod = -1;
			if(j == column)
				columnMod= -1;
			if(i != row && j != column)
			{
				legion.entries[i+rowMod][j+columnMod] = this->entries[i][j];
			}
		}
		columnMod = 0;
	}
	return legion;
}

/*-----------------------------------------------------------------------------------------
FUNCITON NAME: det()
PURPOSE: determinant of a amtrix
RETURNS: T
NOTES: uses recursion
-----------------------------------------------------------------------------------------*/
template <typename T>
T Matrix_ops<T>::det() const
{
	if( !(this->square()) )
		throw typename Matrix<T>::miss_size_error("Cannot take determinant of unsquare matrix\n");

	T determinant;
	determinant = 0;
	Matrix_ops<T> A = *this;
	int multiple = -1;
	if(A.c == 2)
	{
		determinant = A.entries[0][0]*A.entries[1][1]-A.entries[0][1]*A.entries[1][0];
		return determinant;
	}
	for(int i = 0; i < A.c; i++)
	{
		multiple *=-1;

		determinant += A.entries[0][i]*multiple*( (A.exclude(0,i)).det() );
	}
	return determinant;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: trans
PURPOSE: transpose a matrix
RETURNS: Matrix_ops<T>
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::trans() const
{
	Matrix_ops<T> matFromBay(this->c, this->r);
	for(int i = 0; i < matFromBay.r; i++)
	{
		for(int j = 0; j < matFromBay.c; j++)
		{
			matFromBay.entries[i][j] = this->entries[j][i];
		}
	}
	return matFromBay;

}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: inv()
PURPOSE: inverse of a matrix
RETURNS: Matrix_ops<T>
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::inv() const
{
	T det = this->det();

//Alex, these 2 lines arent super working
	if( det == 0)
		throw typename Matrix<T>::det_zero_error("Cannot take inverse if determnant is zero\n");

	Matrix_ops<T> inverse((this->cofactor()).trans());

	for(int i = 0; i < inverse.r; i++)
	{
		for(int j = 0; j < inverse.c; j++)
		{
			inverse.entries[i][j] /= det;
		}
	}
	return inverse;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: cofactor
PURPOSE: returns the cofactor matrix
RETURNS: Matrix_ops<T>
NOTES: cofactor matrix is a matrix where each entry has been replaced by the cofactor to
	   that cell
-----------------------------------------------------------------------------------------*/
template <typename T>
Matrix_ops<T> Matrix_ops<T>::cofactor() const
{
	Matrix_ops<T> co(this->r, this->c);

	for(int i = 0; i < co.r; i++)
	{
		for(int j = 0; j < co.c; j++)
		{
			co.entries[i][j] = (this->exclude(i,j)).det();
		}
	}
	return co;
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
	{
		return true;
	}
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
FUNCTION NAME: rows
PURPOSE: returns number of rows in a Matrix
RETURNS: int
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
int Matrix<T>::rows()
{
	return r;
}

/*-----------------------------------------------------------------------------------------
FUNCTION NAME: columns
PURPOSE: return number of columns in a matrix
RETURNS: int
NOTES:
-----------------------------------------------------------------------------------------*/
template <typename T>
int Matrix<T>::columns()
{
	return c;
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