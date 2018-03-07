#include<iostream>
#include<vector>

using namespace std;

int main() {


	int row, col, i, j;
	row = 5;
	col = 6;

	/*cout << "Enter the number of rows of matrix: ";
	cin >> row;
	cout << "Enter the number of columns of the matrix: ";
	cin >> col;*/

	vector<vector<int>> matrix(row);

	/*cout << "Enter the elements of the matrix:" << endl;
	for (i = 0; i < row; i++)
	{
		matrix[i].resize(col);

		for (j = 0; j < col; j++)
		{
			cin >> matrix[i][j];
		}
	}*/


	for (i = 0; i < row; i++)
	{
		matrix[i].resize(col);
	}
	
	matrix[0] = { 1, 2, 3, 4, 5, 6 };
	matrix[1] = { 8, 9, 1, 2, 3, 4 };
	matrix[2] = { 1, 1, 1, 2, 3, 4 };
	matrix[3] = { 4, 3, 2, 1, 1, 1 };
	matrix[4] = { 5, 6, 7, 8, 9, 0 };

	cout << "You entered:" << endl;
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < col; j++)
		{
			cout << matrix[i][j]<<"   ";
		}

		cout << endl;
	}

	int nrow = row;
	int sum = 0;
	int ncol = col;
	int temp;
	vector<vector<int>> tmatrix;
	while (nrow > 1)
	{
		//Find the sum of first row
		for (i = 0; i < ncol; i++)
		{
			sum += matrix[0][i];
		}
		

		//Save the rotated matrix in a temprorary matrix
		tmatrix.resize(ncol);

		int count =  0;
		for(i = ncol-1; i > 0; i--)
		{
			//tmatrix[count].resize(nrow-2);
			for (j = 1; j < nrow-1; j++)
			{
				tmatrix[count].push_back(matrix[j][i]);

			}
			++count;
		}

		//Decrease the row count by 2
		nrow -= 2;


		//When we rotate counter clockwise the number of row and column will be interchanged.
		temp = nrow;
		nrow = ncol;
		ncol = temp;

		//Swap the matrix
		matrix.swap(tmatrix);

		//Clear the temprorary matrix
		tmatrix.clear();

	}


	cout <<endl<< "The final sum is" << sum;

}