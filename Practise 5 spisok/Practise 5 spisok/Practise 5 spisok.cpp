// Practise 5 spisok.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Merkoff.h"
#include "iostream"
#include "conio.h"
#include "String"

using namespace std;

int main()
{
	Merkoff List;
	for (int i = 0; i < 2; i++)
	{
		if (!List.add())
		{
			return -1;
		}
	}
	List.progon();
	_getch();
    return 0;
}

// в main cin работает