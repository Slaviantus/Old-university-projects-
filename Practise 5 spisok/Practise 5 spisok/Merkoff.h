#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Patients
{
	string name;
	string zodiak;
	int date[3];
	Patients *next;
};
class Merkoff
{
	Patients *head;
	Patients *tail;
public:
	Merkoff();
	void add();
	~Merkoff();
};

