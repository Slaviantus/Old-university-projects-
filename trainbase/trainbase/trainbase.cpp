// trainbase.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "string"

using namespace std;

class train
{
	int number = 0;
	int carnum = 0;
	string start;
	string finish;
	void fillarray();
	class carriage
	{
		string type;
	public:
		carriage();
		~carriage();
	};
	carriage *wagen = new carriage[carnum];
public:
	train();
	void Show();
	~train();
};



void train::fillarray()
{
	
}



void train::Show()
{
	cout << "train №:" << number << " From:" << start << " to:" << finish << endl;
}



train::train()
{
	cout << "Enter number of train" << endl;
	cin >> number;
	cout << "Enter the total number of carriges" << endl;
	cin >> carnum;
	cout << "Enter start station" << endl;
	cin >> start;
	cout << "Enter destination" << endl;
	cin >> finish;
	fillarray();
}



train::~train()
{

}



train::carriage::carriage(int number, char type)
{

}



train::carriage::~carriage()
{

}




int main()
{
	train a;
	a.Show();
	return 0;
}