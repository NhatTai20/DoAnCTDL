#include"HePhuongTrinh.h"
/*Thuan toan tim dang bac thang rut gon cua A = (aij) thuoc Mmxn
B1: cho i:=1, j:= 1
B2: neu i > m hoac j > n thi ket thuc
B3: +neu aij != 0 thi thuc hien cac phep bien doi sau:
		(1/aij)*di
		dk-akj*di voi moi k != i
	sau do i:= i+1, j:= j+1 va quay ve buoc 2
	+neu aij = 0 thi sang buoc 4
B4:+neu akj != 0 voi mot k>i nao do thi chon k nhu vay va thuc hien phep bien doi di<->dk va quay ve buoc 3
   +neu akj = 0 voi moi k>i thi j:=j+1 va quay ve buoc 2*/
void Matrix::EchelonCompactMatrix(int _eleminateCol)//tim dang bac thang rut gon cua ma tran
{
	int rows = 0, cols = 0;
	while (rows < _row && cols < _col - _eleminateCol)
	{
		if (_matrix[rows][cols] != 0) {
			float radiusMain = float(1.0 / _matrix[rows][cols]);

			for (int i = 0; i < _col; i++)
			{
				//  Di = (1/Aij)*Di
				_matrix[rows][i] = radiusMain * _matrix[rows][i];
			}
			for (int k = 0; k < _row; k++)
			{
				float radiusExtra = _matrix[k][cols];
				for (int minusCol = 0; minusCol < _col; minusCol++)
				{
					if (rows != k) {
						//  Dk = Dk - Akj * Di
						_matrix[k][minusCol] = (_matrix[k][minusCol] - radiusExtra * _matrix[rows][minusCol] == 0) ? 0 : _matrix[k][minusCol] - radiusExtra * _matrix[rows][minusCol];

					}
				}
			}
			rows++;//i:=i+1
			cols++;//j:=j+1

		}
		else {
			for (int k = rows; k < _row; k++) {
				if (_matrix[k][cols] != 0) {
					//Swap(_matrix[k], _matrix[rows]): hoan doi 2 dong k va rows
					for (int i = 0; i < _col; i++)
					{
						int temp = _matrix[k][i];
						_matrix[k][i] = _matrix[rows][i];
						_matrix[rows][i] = temp;
					}
					break;
				}
				else {
					cols++;//j:=j+1
					break;
				}
			}
		}
	}
}

int Matrix::Rank()
{
	EchelonCompactMatrix(0);

	int rank = _row;
	for (int rows = 0; rows < _row; rows++)
	{
		bool flag = 0;
		for (int cols = 0; cols < _col; cols++)
		{
			if (_matrix[rows][cols] != 0)
			{
				flag = 1;
			}
		}
		if (flag == 0) rank--;//neu co 1 dong toan 0 thi rank = rank - 1
	}
	return rank;
}
void Matrix::SystemOfLinearEquations()
{
	EchelonCompactMatrix(1);

	cout << "He bac thang rut gon:" << endl;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << _matrix[i][j] << "\t";
		}
		cout << endl;
	}
	_col--;
	int rankMatrix = Rank();
	_col++;

	int RankNew = Rank();

	//TH co nghiem duy nhat
	int n = _col - 1; //max(_row, _col - 1);
	if (rankMatrix == n && rankMatrix == RankNew) {
		cout << "Phuong trinh co nghiem duy nhat: \n";
		for (int i = 0; i < _row; i++)
		{
			cout << "a" << i + 1 << " = " << _matrix[i][_col - 1] << "\n";
		}
	}
	else
		if (rankMatrix + 1 == RankNew) //r(a~)=r(a)+1
			cout << "Phuong trinh vo nghiem\n";
		else//r(a) = r(a) < n
		{
			for (int i = 0; i < n; i++)
			{
				cout << "a" << i + 1 << " = ";
				if (i < rankMatrix)
					cout << _matrix[i][_col - 1];
				else {
					cout << "t" << i - rankMatrix + 1 << "\n";
					continue;
				}

				bool flag = 0;
				for (int j = 0; j < _col - 1; j++)
				{
					if (flag == 1)
					{
						if (_matrix[i][j] != 0)
						{
							if (_matrix[i][j] > 0)
								cout << " - ";//chuyen ve doi dau
							else
								if (_matrix[i][j] < 0)
									cout << " + ";//chuyen ve doi dau
							if (_matrix[i][j] == 1 || _matrix[i][j] == -1)
							{
								cout << "t" << j - rankMatrix + 1;
							}
							else
								cout << fabs(_matrix[i][j]) << "*t" << j - rankMatrix + 1;
						}
					}
					else {

						if (_matrix[i][j] != 0) flag = 1;
					}
				}
				cout << "\n";
			}
		}
}
int max(int a, int b)
{
	if (a > b)return a;
	else return b;
}
void Matrix::Nhap()
{
	cout << "Nhap so dong cua ma tran: ";
	cin >> _row;
	cout << "\nNhap so cot cua ma tran: ";
	cin >> _col;
	cout << "Nhap cac phan tu cua ma tran: ";
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> _matrix[i][j];
		}
	}
}
void Matrix::Xuat()
{
	cout << "Ma tran: " << endl;
	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _col; j++)
		{
			cout << _matrix[i][j] << "\t";
		}
		cout << endl;
	}
}