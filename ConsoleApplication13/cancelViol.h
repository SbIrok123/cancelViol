#pragma once
#include "Date.h"
struct cancelViol
{
	Date date;
	float entered;
	
	void NewTransaction() 
	{
		cout << "Enter violation date - " << endl;
		date.fillDate();
		cout << "Enter sum - ";
		cin >> entered;
	}
};