// practise 5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "cstdio"
#include "cstring"
#include "cstdlib"

using namespace std;

struct ZNAK
{
	char name[20];
	char zodiac[20];
	int date[3];
};

int main()
{
	const int n = 8;
	ZNAK Murkoff[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter the patient name" << endl;
		gets_s(Murkoff[i].name);
		cout << "Enter the patient's birth date" << endl;
	}
	cout << Murkoff[0].name << endl;
	_getch();
    return 0;
}

