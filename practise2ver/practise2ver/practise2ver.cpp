// practise2ver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cmath"

using namespace std;

void Sortie()
{

}
int main()
{
	double A = 0;
	double B[5];
	cout << "Enter the coordinate of point A" << endl;
	cin >> A;
	cout << "Enter coordinates of points B" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter the coordinate of point B" << i + 1 << endl;
		cin >> B[i];
		B[i] = abs(A - B[i]);
	}//done
    return 0;
}

