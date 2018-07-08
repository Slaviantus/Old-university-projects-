// practise3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

void fillarray(double *arr, int str, int col)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << "Enter the element of " << i + 1 << " String and " << j + 1 << " Column" << endl;
			cin >> arr[i * col + j];
		}
	}
}
void changestrings(double *arr, int str, int col, int str1, int str2, double *keeparr)
{
	for (int j = 0; j < col; j++)
	{
		keeparr[j] = arr[str1 * col + j];
	}
	for (int j = 0; j < col; j++)
	{
		arr[str1 * col + j] = arr[str2 * col + j];
	}
	for (int j = 0; j < col; j++)
	{
		arr[str2 * col + j] = keeparr[j];

	}
}
void showarray(double *arr, int str, int col)
{
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << arr[i * col + j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	double A[100], B[20];
	int n, m, str1, str2;
	cout << "Enter the number of strings" << endl;
	cin >> n;
	cout << "Enter the number of columns" << endl;
	cin >> m;
	cout << "Enter the number of strings, which you want to change\nthe First string" << endl;
	cin >> str1;
	cout << "the Second string" << endl;
	cin >> str2;
	if (m < 0 || n < 0 || str1 < 1 || str1 > n || str2 < 1 || str2 > n)
	{
		cout << "Its wrong" << endl;
		_getch();
		return -1;
	}
	str1--;
	str2--;
	fillarray(A, n, m);
	cout << "The array before changes" << endl;
	showarray(A, n, m);
	changestrings(A, n, m, str1, str2, B);
	cout << "The array after changes" << endl;
	showarray(A, n, m);
	_getch();
	return 0;
}


