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

template <typename T>
bool Matrix_ops::same_sizeness(Matrix_ops& const matthew)
{
	if(r == matthew.r && c == matthew.c)
		return true;
	return false;
}


/*-----------------------------------------------------------------------------------------

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
/*----------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------*/
template <typename T>
ostream& operator << (ostream& out, Matrix<T>& mat) 
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