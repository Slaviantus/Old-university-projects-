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
	class carriage
	{
		int number;
		string type;
	public:
		void Setdata(int num, char t);
		~carriage();
	};
public:
	train();
	void Show();
	~train();
};



void train::Show()
{
	cout << "train №:" << number << " From:" << start << " to:" << finish << endl;
}



train::train()
{
	
	cout << "Enter number of train" << endl;
	cin >> number;
	cout << "Enter the total number of carriages" << endl;
	cin >> carnum;
	cout << "Enter start station" << endl;
	cin >> start;
	cout << "Enter destination" << endl;
	cin >> finish;
	carriage *wagen = new carriage[carnum];
	for (int i = 0; i < carnum; i++)
	{
		char t;
		cout << "Enter the type of carriage: c - econom, b - busines, a - royal" << endl;
		cin >> t;
		wagen[i].Setdata(i + 1, t);
	}
}



train::~train()
{

}


 void train::carriage::Setdata(int num, char t)
{
	 number = num;
	 type = t;
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