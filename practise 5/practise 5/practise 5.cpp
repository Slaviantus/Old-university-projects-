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
		cout << "Day: " << endl;
		cin >> Murkoff[i].date[0];
		cout << "Month: " << endl;
		cin >> Murkoff[i].date[1];
		cout << "Year: " << endl;
		cin >> Murkoff[i].date[2];
		cout << "Enter Zodiak sigh: " << endl;
		gets_s(Murkoff[i].zodiac);
		cout << "Patient name: " << Murkoff[i].name << " Birth date: " << Murkoff[i].date[0] << "." << Murkoff[i].date[1] << "." << Murkoff[i].date[2] << " Zodiak sigh: " << Murkoff[i].zodiac << endl;
	}
	_getch();
	return 0;
}

