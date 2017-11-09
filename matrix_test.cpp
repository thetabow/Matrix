//file: matrix_test.cpp
//description: test matrix
//compiler: GNU g++ on linux

#include "Matrix.h"

/*-----------------
main function to 
test out Matrix
next one reads 
files using command
line arguments
returns 0
-----------------*/

int main(int argc, char *argv[])
{
	int *ptr = nullptr;
	int i, j, k;
	int m, n;
	char let_x;
	char file1[20];
	ifstream infile;

	if (argc < 3)
	{
		cout << "Not enough Arguments \n\n";
		return 0;
	}

	if (strcmp(argv[1], "-inp") == 0)
	{
		strcpy(file1, argv[2]);
		strcat(file1, ".mtx");
		infile.open(file1);

		if (!infile)
		{
			cout << "\nError opening file: " << file1 << "\n\n";
			return 0;
		}
	}

	infile >> m >> let_x >> n;

	Matrix mat1(m,n);

	for(i = 0; i < m; i++)
	{
		for(j = 0; j < n; j++)
		{
			infile >> k;
			mat1.set(i,j,k);
		}
	}
	mat1.display();
	infile.close();
	return 0;
}