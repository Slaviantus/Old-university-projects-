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
	//gets_s(patient->name);
	cin >> patient->name;
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
		cout << "============================================" << endl;
		cout << "         The Patient has been added         " << endl;
		show(patient);
		cout << "============================================" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void Merkoff::Entermonth()
{
	int month;
	cout << "Enter number of month:" << endl;
	cin >> month;
	search(month);
}

void Merkoff::Del(Patients *ukazatel)
{
	Patients *zapas = ukazatel;
	ukazatel = head;
	while (ukazatel != NULL)
	{
		if (ukazatel == zapas)
		{
			head = zapas->next;
			delete zapas;
			break;
		}
		if (ukazatel->next == zapas)
		{
			if (zapas->next == NULL)
			{
				ukazatel->next = NULL;
				tail = ukazatel;
				delete zapas;
				break;
			}
			ukazatel->next = zapas->next;
			delete zapas;
			break;
		}
		ukazatel = ukazatel->next;
	}

}

void Merkoff::showall()
{
	Patients *ukazatel = head;
	cout << "All Patients" << endl;
	while (ukazatel != NULL)
	{
		cout << "---------------------------------" << endl;
		show(ukazatel);
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

void Merkoff::search(int month)
{
	Patients *ukazatel = head;
	cout << "Patients who were born in this month" << endl;
	while (ukazatel != NULL)
	{
		if (ukazatel->date[1] == month)
		{
			show(ukazatel);
		}
		ukazatel = ukazatel->next;
	}

}

void Merkoff::show(Patients *ukazatel)
{
	cout << "==============================" << endl;
	cout << "Name: " << ukazatel->name << endl;
	cout << "Birth date: " << ukazatel->date[0] << "." << ukazatel->date[1] << "." << ukazatel->date[2] << endl;
	cout << "Zodiak sign: " << ukazatel->zodiak << endl;
	cout << "This adress: " << ukazatel << endl;
	cout << ukazatel->next << endl;
	cout << "==============================" << endl;
}

void Merkoff::kill()
{

	while (head != NULL)
	{
		Patients *ukazatel = head;
		head = head->next;
		delete ukazatel;
	}
}




void Merkoff::menu()
{
	cout << "==========  Merkoff patients data  ==========" << endl;
	int button = 0;
	bool work = true;
	bool check = true;
	while (check)
	{
		cout << "Add patient ---------- 1" << endl;
		cout << "Exit------------------ 2" << endl;
		cin >> button;
		switch (button)
		{
		case 1:
		{
			if (add())
			{
				check = false;
			}
			break;
		}
		case 2:
		{
			work = false;
		}
		}
	}
	button = 0;
	while (work)
	{
		cout << "Add patient ---------- 1" << endl;
		cout << "Delete patient ------- 2" << endl;
		cout << "Search by month ------ 3" << endl;
		cout << "Show all patients ---- 4" << endl;
		cout << "Exit------------------ 5" << endl;
		cin >> button;
		switch (button)
		{
		case 1:
		{
			add();
			break;
		}
		case 2:
		{
			Patients *ukazatel = head;
			string entername;
			bool find = false;
			while (ukazatel != NULL)
			{
				cout << ukazatel->name << endl;
				ukazatel = ukazatel->next;
			}
			cout << "---------------------------------------" << endl;
			cout << "Enter the name which you want to delete" << endl;
			cin >> entername;
			ukazatel = head;
			while (ukazatel != NULL)
			{
				if (entername == ukazatel->name)
				{
					Del(ukazatel);
					find = true;
					break;
				}
				ukazatel = ukazatel->next;
			}
			if (!find)
			{
				cout << "There is no patient" << endl;
			}
			break;
		}
		case 3:
		{
			Entermonth();
			break;
		}
		case 4:
		{
			showall();
			break;
		}
		case 5:
		{
			work = false;
			break;
		}

		}
	}

}


Merkoff::~Merkoff()
{
	kill();
}

