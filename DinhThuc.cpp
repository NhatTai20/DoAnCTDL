#include"DinhThuc.h"
void Input(int matrix[10][10], int& n)
{
	cout << "Enter the size of the matrix: ";
	cin >> n;
	cout << "Enter the elements of the matrix:\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> matrix[i][j];
			cout << endl;
		}

}
void Output(int matrix[10][10], int n)
{
	cout << "The entered matrix is:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}
int determinant(int matrix[10][10], int n) {
	int det = 0;
	int submatrix[10][10];//tao 1 ma tran rong de luu A(i|j)
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) 
			{//vi tinh dinh thuc theo dong 1 cua ma tran nen i bat dau tu 1 thay vi 0
				int subj = 0;
				for (int j = 0; j < n; j++)
				{
					if (j == x)//neu chi so cot bang gia tri x
						continue;//bo qua gia tri nay
					submatrix[subi][subj] = matrix[i][j];//neu chi so cot khac x thi them gia tri A[i][j] vao ma tran A(i|j)
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));//tinh dinh thuc theo dong dau tien cua ma tran
		}
	}
	return det;
}