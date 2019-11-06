#include"Vector.h"
void Vector::Nhap()
{
	cout << "\nNhap so phan tu cua vector: ";
	cin >> n;
	cout << "\nNhap cac thanh phan cua vector";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap phan tu " << "v[" << i + 1 << "]: ";
		cin >> v[i];
	}
}
void Vector::Xuat()
{
	cout << "(";
	for (int i = 0; i < n; i++)
	{
		cout << " " << v[i];
	}
	cout << ")";
	cout << endl;
}

Vector Vector::Add(Vector b)
{
	if (n != b.n)
	{
		cout << "2 vector khong co cung so luong phan tu! Nhap lai vector!";
		b.Nhap();
	}
	Vector c;//tao 1 vector moi de luu ket qua
	c.n = n;
	for (int i = 0; i < n; i++)
	{
		c.v[i] = v[i] + b.v[i];//cong tung phan tu thu i cua vector 1 voi phan tu thu i cua vector 2
	}
	return c;
}
Vector Vector::Multiplied(float a)
{
	Vector c;
	c.n = n;
	for (int i = 0; i < n; i++)
	{
		c.v[i] = v[i] * a;//nhan tat ca phan tu cua vector voi a
	}
	return c;
}

Vector::Vector()
{
	for (int i = 0; i < n; i++)
	{
		v[i] = 0;
	}
}