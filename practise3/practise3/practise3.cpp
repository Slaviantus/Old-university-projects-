// practise3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

int main()
{
	double A[100];
	int n, m, str1, str2;
	cout << "Enter the number of strings" << endl;
	cin >> n;
	cout << "Enter the number of columns" << endl;
	cin >> m;
	cout << "Enter the number of strings, which you want to change\nthe First string" << endl;
	cin >> str1;
	cout << "the Second string" << endl;
	cin >> str2;
	if (m < 0 || n < 0 || str1 < 0 || str1 > n || str2 < 0 || str2 > n)
	{
		cout << "Its wrong" << endl;
		_getch();
		return -1;
	}
	//fillarray(A,)
	_getch();
    return 0;
}

