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
#include <cstdlib>
#include <ctime>
using namespace std;

//prototypes
int options(string);
bool needsTwo(string arg);
void randomFill(char * fileName, int rows, int columns);

/*---------------------------------------------------------------------------------------
FUNCTION NAME: main
PURPOSE: driver function
RETURNS: int
NOTES: different set ups for different types are commented out, please only have
		the type you want to use uncommented out
---------------------------------------------------------------------------------------*/
int main(int argc, char * argv[])
{
	unsigned seed = time(0);
	srand(seed);

	//Complex with fraction set up:
	//Matrix_ops<Complex<Fraction>> A, B, C;
	//Complex<Fraction> num;

	//Complex with decimal set up:
	//Matrix_ops<Complex<double>> A, B, C;
	//Complex<double> num;

	//Complex with ints set up:
	//Matrix_ops<Complex<int>> A, B, C;
	//Complex<int> num;

	//Fraction real set up:
	//Matrix_ops<Fraction> A, B, C;
	//Fraction num;

	//long set up
	Matrix_ops<long> A, B, C;
	long num;

	//Matrix_ops<double> A,B,C;
	//double num;

	num = 0;
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

	if (argc >= 3 && argv[1] != "-rand")
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
		inFile1.close();
	}
	if(needsTwo(argv[1]))
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
		inFile2.close();
	}
	for(int i = 0; i < argc; i++)
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

	switch(options(argv[1])) {
		case 1: { //inp
			C = A; break;
		}
		case 2: { //add
			C = (A + B); break;
		}
		case 3: { //sub
			C = A - B; break;
		}
		case 4: { //mul
			C = A * B; break;
		}
		case 5: {//eq
			if(A==B)
				cout << "\nThe matrices are the same\n";
			else
				cout << "\nThe matrices are not the same\n";
			break;
		}
		case 6: { //transpose
			C = A.trans();
			break;
		}
		case 7: { //inverse
			C = A.inv();
			break;
		}
		case 8: { //det
			num = A.det();
			cout << num << endl;
			if(output)
				outFile << num << endl;
			return 0;
		}
		case 9: { //reduce row
			C = A.reduceRow();
			break;
		}
		case 10: { //testing out cofactor
			C = A.cofactor();
			break;
		}
		case 12: { //solve
			C = A.solve();
			break;
		}
		case 11: { //randomly fill a matrix
			int r = stoi(string(argv[3]));
			int c = stoi(string(argv[4]));
			randomFill(argv[2], r, c);
			break;
		}
		default: {
			cout << "\nNothing here yet\n"; break;
		}
	}


	cout << endl << C << endl;
	
	if(output)
	{
		outFile << C.rows() << "x" << C.columns() << endl;
		outFile << C;
	}

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
		if(argName == "-rre")
			return 9;
		if(argName == "-co")
			return 10;
		if(argName == "-rand")
			return 11;
		if(argName == "-solve")
			return 12;
		return 0;
}

/*----------------------------------------------------------------------------------
FUNCTION NAME: needsTwo
PURPOSE: assesses if program needs 2 matrix arguments
RETURNS: bool
NOTES:
----------------------------------------------------------------------------------*/
bool needsTwo(string arg)
{
	if(arg == string("-add") || arg == string("-sub") || arg == string("-mul") || arg == string("-eq"))
		return true;
	return false;

}

/*----------------------------------------------------------------------------------
FUNCTION NAME: rnadomFill
PURPOSE: fill a matrix of given size with random numbers so i dont have to
RETURNS: void
NOTES:
----------------------------------------------------------------------------------*/
void randomFill(char* file, int rows, int columns)
{

	ofstream outPut;
	char fileName[20];
	strcpy(fileName, file);
	strcat(fileName, ".mtx");

	cout << "opening: " << fileName << endl;
	outPut.open(fileName);
	if(!outPut)
	{
		cout << "Error opening file\n";
		return;
	}

	outPut << rows << "x" << columns << endl;

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < columns; j++)
		{
			outPut << (rand() % 10 - 4) << " " ;
		}
		outPut << endl;
	}
	
	outPut.close();

}