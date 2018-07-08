// practise2ver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cmath"

using namespace std;

void Sortie(double *arr, const int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int max = 0;
		int maxnum = 0;
		for (int j = i; j < n; j++)
		{
			if (arr[j] > max)
			{
				max = arr[j];
				maxnum = j;
			}
		}
		arr[maxnum] = arr[i];
		arr[i] = max;
	}
}
void keeparr(double *arr, double *arrkeep, const int n)
{
	for (int i = 0; i < n; i++)
	{
		arrkeep[i] = arr[i];
	}
}
void showpoint(double *arr, double *arrkeep, const int n)
{
	int max = arr[0];
	for (int j = 0; j < n; j++)
	{
		if (max == arrkeep[j])
		{
			cout << "B" << j + 1 << " is the furthest point, the distance is " << max << endl;
		}
	}
}
int main()
{
	const int n = 5;
	double A = 0;
	double B[n];
	double C[n];
	cout << "Enter the coordinate of point A" << endl;
	cin >> A;
	cout << "Enter coordinates of points B" << endl;
	for (int i = 0; i < n; i++)

	{
		cout << "Enter the coordinate of point B" << i + 1 << endl;
		cin >> B[i];
		B[i] = abs(A - B[i]);
	}
	keeparr(B, C, n);
	Sortie(B, n);
	showpoint(B, C, n);
	_getch();
	return 0;
}

