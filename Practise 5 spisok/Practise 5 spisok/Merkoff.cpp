#include "stdafx.h"
#include "Merkoff.h"


Merkoff::Merkoff()
{
	head = NULL;
	tail = NULL;
}

void Merkoff::add()
{
	Patients *patient = new Patients;

	cout << "Enter the name of patient" << endl;
	cin >> patient->name;
	cout << "Enter the patient's birth date: " << endl;
	cout << "Day: ";
	cin >> patient->date[0];
	cout << "Month: ";
	cin >> patient->date[1];
	cout << "Year: ";
	cin >> patient->date[2];

}


Merkoff::~Merkoff()
{
}
