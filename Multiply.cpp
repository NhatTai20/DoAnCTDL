#include"Multiply.h"

void InPutMaTrix(int matrix[10][10], int& m, int& n)
{
	cout << "Enter the row number of the matrix: " << endl;
	cin >> m;
	cout << "Enter the column number of the matrix: " << endl;
	cin >> n;
	cout << "Enter the elements of the matrix: ";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\nMatrix[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> matrix[i][j];
		}
	}
}

void OutPutMatrix(int matrix[10][10], int m, int n)
{
	cout << "The entered matrix is: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
/*Cho 2 ma tran A thuoc Mmxn va B thuoc Mnxp
Khi do tich cua A voi B (AB) la ma tran Mmxn voi
  (AB)ij = Ai1B1j + Ai2B2j + ... + AinBnj*/
void MatrixMultiplication(int a[10][10], int b[10][10], int& r1, int& c1, int& r2, int& c2)
{

	cout << "The first matrix: " << endl;
	InPutMaTrix(a, r1, c1);
	cout << "\nThe second matrix: " << endl;
	InPutMaTrix(b, r2, c2);
	if (c1 != r2)
	{
		cout << "Column of first matrix should be equal to row of second matrix";
	}
	else {
		cout << "The first matrix is: " << endl;
		OutPutMatrix(a, r1, c1);
		cout << "\nThe second matrix is: " << endl;
		OutPutMatrix(b, r2, c2);
		int resume[10][10];//tao mot ma tran phu de luu ket qua
		for (int i = 0; i < r1; ++i)
			for (int j = 0; j < c2; ++j) {
				resume[i][j] = 0;
			}
		for (int i = 0; i < r1; i++)
		{
			for (int j = 0; j < c2; j++) {
				for (int k = 0; k < c1; k++) {
					resume[i][j] += a[i][k] * b[k][j]; //(AB)ij = Ai1B1j + Ai2B2j + ... + AinBnj
				}
			}
		}
		cout << "Product of the two matrices is: " << endl;
		OutPutMatrix(resume, r1, c2);
		cout << endl;
	}
}
