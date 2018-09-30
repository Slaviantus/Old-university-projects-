#pragma once
#include "stdafx.h"
#include "iostream"
#include "String"
#include "cstdio"
#include "cstring"
#include "cstdlib"

using namespace std;

struct Patients
{
	char name[20];
	string zodiak;
	int date[3];
	Patients *next;
};
class Merkoff
{
	Patients *head;
	Patients *tail;
	bool zodiaksign(Patients *ukazatel);
	void search(int month);
	void show(Patients *ukazatel);
	void kill();
	bool add();
	void Entermonth();
public:
	Merkoff();
	void menu();
	~Merkoff();
};

