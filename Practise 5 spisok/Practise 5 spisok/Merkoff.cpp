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

void Merkoff::add()
{
	Patients *patient = new Patients;

	cout << "Enter the name of patient" << endl;
	//cin >> patient->name;
	//cin.get();
	//getline(cin, patient->name);
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
}

void Merkoff::progon()
{
	while (tail->next != NULL)
	{
		//cout << tail->name << endl;
		getline(cout, tail->name);
	}
}


Merkoff::~Merkoff()
{
}
