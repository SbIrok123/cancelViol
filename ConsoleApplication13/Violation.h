#pragma once
#include "Date.h"
#include<cstring>

struct Violation
{
	Date date;
	char info[100] = "";
	float fine = 0;
	void showViolation()
	{
		cout << "\t Date : " << date.toString()<<endl;
		cout << "\t Info : " << info<<endl;
		cout << "\t Fine : " << fine<<" Uah" << endl;
	}
	void fillViolation() {
		cout << "input date - "<<endl;
		date.fillDate();
		cout << "input info - "<<endl;
		cin.ignore();
		cin.getline(info, 100);
		cout << "input fine - " << endl;
		cin >> fine;
	}
};