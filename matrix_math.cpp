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

//prototypes
int options(string);


int main(int argc, char * argv[])
{
	Matrix_ops<int> A, B, C;
	char file1[20];
	char file2[20];
	char outfile[20];
	ofstream outFile;
	bool output = false;

	if(argc < 3)
	{
		cout << "Too few arguments\n";
		return 0;
	}
	if (argc >= 3)
	{
		ifstream inFile1;
		strcpy(file1, argv[2]);
		strcat(file1, ".mtx");
		inFile1.open(file1);
		if(!inFile1)
		{
			cout << "Error opening file\n";
			return 0;
		}
		inFile1 >> A;
	}
	if(argc >= 4)
	{
		ifstream inFile2;
		strcpy(file2, argv[3]);
		strcat(file2, ".mtx");
		inFile2.open(file2);
		if(!inFile2)
		{
			cout << "Error opening file\n";
			return 0;
		}
		inFile2 >> B;
	}
	if(argc >= 5)
	{
		for(int i = 4; i < argc; i++)
		{
			if(argv[i] == string("-out"))
			{
				strcat(outfile, argv[i+1]);
				strcat(outfile, ".mtx");
				outFile.open(outfile);
				if(!outFile)
				{
					cout << "Error opening file\n";
					return 0;
				}
				output = true;
			}
		}
	}



	switch(options(argv[1])) {
		case 1: { //inp
			C = A; break;
		}
		case 2: { //add
			C = (A + B);
		}
		case 3: { //sub
			C = A - B; break;
		}
		case 4: { //mul
			C = A * B; break;
		}
		case 5: {//eq
			if(A==B)
				cout << "The matrices are the same\n";
			else
				cout << "The matrices are not the same\n";
			break;
		}
		default: {
			cout << "Nothing here yet\n"; break;
		}
	}


	cout << C << endl;
	if(output)
		outFile << C.rows() << "x" << C.columns() << endl;
		outFile << C;

	cout << "Thanks bye\n";
	return 0;
}


/*----------------------------------------------------------------------------------
FUNCITON NAME: options
PURPOSE: convert argument into int for switch statement
RETUNRS: int
NOTES:
----------------------------------------------------------------------------------*/
int options(string argName)
{

		if(argName == "-inp")
			return 1;
		if(argName == "-add")
			return 2;
		if(argName == "-sub")
			return 3;
		if(argName == "-mul")
			return 4;
		if(argName == "-eq")
			return 5;
		if(argName == "-T")
			return 6;
		if(argName == "-1")
			return 7;
		if(argName == "-det")
			return 8;
		return 0;
}