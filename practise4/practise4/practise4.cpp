// practise4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

void fillarrayA(double *arr, int col)
{
	for (int i = 0; i < col; i++)
	{
		cout << "Enter " << i + 1 << " element of array A" << endl;
		cin >> arr[i];
	}
}
void fillarrayB(double *arrA, int col, int m, double *arrB, int k)
{
	for (int i = 0; i < col + m; i++)
	{
		arrB[i] = arrA[i];
		if ()
		{

		}
	}
}
int main()
{
	int k = 0, m = 0;
	const int n = 9;
	double A[9];
	cout << "Enter k" << endl;
	cin >> k;
	cout << "Enter m" << endl;
	cin >> m;
	if (k < 1 || k > n || m < 1 || m > 10)
	{
		cout << "Its wrong!" << endl;
		return -1;
		_getch();
	}
	cout << "Fill the array A" << endl;
	fillarrayA(A, n);
	double *B = new double[n + m];
	fillarrayB(A, n, m, B, k);
	_getch();
    return 0;
}
