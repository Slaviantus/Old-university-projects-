// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"

using namespace std;

int main()
{
	FILE *trouble;
	char A[10];
	cout << "Enter the word";
	for (int i = 0; i < 10; i++)
	{
		cin >> A[i];
		if (A[i] == '.')
		{
			break;
		}
	}
	errno_t err = fopen_s(&trouble, "C:\\Users\\Slavka\\Documents\\doubletrouble.txt", "w");
	fprintf(trouble, "Govno");
	fclose(trouble);
	_getch();
    return 0;
}

