/*-------------------------------------------------------------------------------------------------------------
FILE NAME: matrix_math.cpp

DESCRIPTION: driver program for Matrix class

PURPOSE: demonstrate Matrix class and matrix_ops with command line

USAGE: ./matrix_math followed by parameter 

EXAMPLES: ./matrix_math -h , ./matrix_math -add A B , ./matrix_math -det A

PARAMETERS: -h, -inp, -out, -add, -sub, -mul, -eq, -T, -1, -det, -solve
	    all have other parameters that go with them, see -h command for details

EXIT CODES: 0 success, otherwise failure

COMPILATION: command "make" and use given makefile

NOTES:  must manually switch which type of a matrix you are using by commenting and uncommenting parts in the
		driver...pretty well documented on which parts those are. 

		currently using type: double

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
Zuriah Quinton  12/06/17		4.3				help screen
--------------------------------------------------------------------------------------------------------------*/
#include "Matrix.h"
#include <cstdlib>
#include <ctime>
using namespace std;

//prototypes

int options(string);
void helpscreen();
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

	//double set up
	Matrix_ops<double> A,B,C;
	double num;

	//long set up
	//Matrix_ops<long> A, B, C;
	//long num;

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




	num = 0;

	char outfile[20];
	ofstream outFile;
	bool output = false;

	if(string(argv[1]) == "-h") {
		helpscreen();
		return 0;
	}

	//any set of arguments requires more than 3 arguments
	if(argc < 3)
	{
		cout << "Too few arguments\n";
		return 0;
	}

	//exclude rand command here because it does crazy other things
	if (argc >= 3 && argv[1] != "-rand")
	{
		if(!A.openfile(argv[2])) 
			return 0;
	}
	//see needsTwo function for more details, but opens a second file if needed
	if(needsTwo(argv[1]))
	{
		if(!B.openfile(argv[3])) 
			return 0;
	}
	//checks for any specified output file
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
			//a bool to keep track of if printing to file at end is necessary
			output = true;
		}
	}

	//see options() function for more details, but if changes which command is used
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

	//outputs the matrix to the screen
	cout << C.rows() << "x" << C.columns();
	cout << endl << C << endl;
	
	//if specified earlier, output matrix to file
	if(output)
	{
		outFile << C.rows() << "x" << C.columns() << endl;
		outFile << C;
	}

	cout << "Thanks bye" << endl;
	return 0;
}


/*----------------------------------------------------------------------------------
FUNCITON NAME: options
PURPOSE: convert argument into int for switch statement
RETUNRS: int
NOTES: this function takes in the string that is the argument for which opertaion
	   to perform, and from there returns a number so that the switch statement works
	   there isn't really a logical order to these, it is just the order i added 
	   these operations to the program. 
	   returns 0 if it is an invalid argument
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
NOTES:	this function is just my neat way of checking for a few argument to see
		which ones need 2 matrices....(this then triggers in the driver the opening
		of a second matrix file)
----------------------------------------------------------------------------------*/
bool needsTwo(string arg)
{
	if(arg == string("-add") || arg == string("-sub") || arg == string("-mul") || arg == string("-eq"))
		return true;
	return false;

}

/*----------------------------------------------------------------------------------
FUNCTION NAME: randomFill
PURPOSE: fill a matrix of given size with random numbers (INTS ONLY) so i dont have to
RETURNS: void
NOTES:  this is the funciton I made to fill a matrix with random numbers
		this was made around when i did the determinant because i kept accidentally
		making linearly dependent rows giving me a determinant of 0 and made me 
		think that i had broken everything, when really i was just being a goob

COMMAND TO USE:  ./matrix_math -rand A 3 4

					this will randomly fill A.mtx with a 3x4 matrix
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

	return;
}

/*----------------------------------------------------------------------------------
FUNCTION NAME: helpscreen
PURPOSE: print helpscreen
RETURNS: void
NOTES: 
----------------------------------------------------------------------------------*/
void helpscreen()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	cout << "Command:  Example uses:               What it does: " << endl
		 << "--------------------------------------------------------------------------------------\n"
		 << "-inp      ./matrix_math -inp A        display contents of A" << endl
		 << "-out      ./matrix_math cmds -out B   performs cmds then outputs to B.mtx" << endl
		 << "-add      ./matrix_math -add A B      performs A + B operation" << endl
		 << "-sub      ./matrix_math -sub A B      performs A - B operation" << endl
		 << "-mul      ./matrix_math -mul A B      performs A * B operation" << endl
		 << "-eq       ./matrix_math -eq A B       test matrices for equality" << endl
		 << "-T        ./matrix_math -T A          transposes matrix A" << endl
		 << "-1        ./matrix_math -1 A          finds the inverse of A" << endl
		 << "-det      ./matrix_math -det A        finds determinant of A" << endl
		 << "-solve    ./matrix_math -solve A      finds solution to linear equations" << endl
		 << "-rre      ./matrix_math -rre A        performs gaussian elimination on A" << endl
		 << "-rand     ./matrix_math -rand A 2 3   fills A matrix with a 2x3 random matrix of ints" << endl << endl;

}

