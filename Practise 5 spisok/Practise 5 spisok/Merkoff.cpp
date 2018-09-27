#include "stdafx.h"
#include "iostream"
#include "String"
#include "Merkoff.h"
#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "conio.h"

using namespace std;


Merkoff::Merkoff()
{
	head = NULL;
	tail = NULL;
}

bool Merkoff::add()
{
	Patients *patient = new Patients;

	cout << "Enter the name of patient" << endl;
	gets_s(patient->name);
	cout << endl;
	cout << "Enter the patient's birth date: " << endl;
	cout << "Day: ";
	cin >> patient->date[0];
	cout << endl;
	cout << "Month: ";
	cin >> patient->date[1];
	cout << endl;
	cout << "Year: ";
	cin >> patient->date[2];
	cout << endl;
	if (patient->date[1] < 1 || patient->date[1] > 12 || patient->date[0] < 1)
	{
		cout << "Its wrong!" << endl;
		return false;
	}
	patient->next = NULL;
	if (head == NULL)
	{
		head = patient;
		tail = patient;
	}
	else
	{
		tail->next = patient;
		tail = patient;
	}
	while (getchar() != '\n');
	if (zodiaksign(patient))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Merkoff::progon()
{
	Patients *ukazatel = head;
	while (ukazatel != NULL)
	{
		cout << ukazatel->name << endl;
		cout << ukazatel->zodiak << endl;
		ukazatel = ukazatel->next;
	}
}

bool Merkoff::zodiaksign(Patients *ukazatel)
{
	switch (ukazatel->date[1])
	{
	case 1:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 19)
		{
			ukazatel->zodiak = "Capricorn";
		}
		else
		{
			ukazatel->zodiak = "Aquarius";
		}
		break;
	}
	case 2:
	{
		if (ukazatel->date[0] > 28)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 18)
		{
			ukazatel->zodiak = "Aquarius";
		}
		else
		{
			ukazatel->zodiak = "Pisces";
		}
		break;
	}
	case 3:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 20)
		{
			ukazatel->zodiak = "Pisces";
		}
		else
		{
			ukazatel->zodiak = "Aries";
		}
		break;
	}
	case 4:
	{
		if (ukazatel->date[0] > 30)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 20)
		{
			ukazatel->zodiak = "Aries";
		}
		else
		{
			ukazatel->zodiak = "Taurus";
		}
		break;
	}
	case 5:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 20)
		{
			ukazatel->zodiak = "Taurus";
		}
		else
		{
			ukazatel->zodiak = "Gemini";
		}
		break;
	}
	case 6:
	{
		if (ukazatel->date[0] > 30)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 20)
		{
			ukazatel->zodiak = "Gemini";
		}
		else
		{
			ukazatel->zodiak = "Cancer";
		}
		break;
	}
	case 7:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 22)
		{
			ukazatel->zodiak = "Cancer";
		}
		else
		{
			ukazatel->zodiak = "Leo";
		}
		break;
	}
	case 8:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 22)
		{
			ukazatel->zodiak = "Leo";
		}
		else
		{
			ukazatel->zodiak = "Virgo";
		}
		break;
	}
	case 9:
	{
		if (ukazatel->date[0] > 30)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 23)
		{
			ukazatel->zodiak = "Virgo";
		}
		else
		{
			ukazatel->zodiak = "Libra";
		}
		break;
	}
	case 10:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 23)
		{
			ukazatel->zodiak = "Libra";
		}
		else
		{
			ukazatel->zodiak = "Scorpio";
		}
		break;
	}
	case 11:
	{
		if (ukazatel->date[0] > 30)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 21)
		{
			ukazatel->zodiak = "Scorpio";
		}
		else
		{
			ukazatel->zodiak = "Sagittarius";
		}
		break;
	}
	case 12:
	{
		if (ukazatel->date[0] > 31)
		{
			cout << "Its wrong!" << endl;
			return false;
		}
		if (ukazatel->date[0] <= 21)
		{
			ukazatel->zodiak = "Sagittarius";
		}
		else
		{
			ukazatel->zodiak = "Capricorn";
		}
		break;
	}
	}
	return true;
}









Merkoff::~Merkoff()
{
}
