#pragma once
#include "Violation.h"
#include "cancelViol.h"
#include "D:\install\ArrayTemplate2.h"
struct Driver
{
	char name[100] = "";
	char carNumber[10] = "";
	int sizeViol = 0;
	int sizeTransactions = 0;
	Violation* arr = nullptr;
	cancelViol* arr2=nullptr;
	void showDrive(){
		cout << "name : " << name<<endl;
		cout << "carNumber : " << carNumber << endl;
		for (int i = 0; i < sizeViol; i++)
		{
			int sum = arr[i].fine;
			for (int j = 0; j < sizeTransactions; j++)
			{
				if (strcmp(arr[i].date.toString(), arr2[j].date.toString())==0 )
				{
					sum -= arr2[j].entered;
				}
			}
			if (sum <= 0)
			{
				for (int j = 0; j < sizeTransactions; j++)
				{
					if (strcmp(arr[i].date.toString(), arr2[j].date.toString()) == 0)
					{
						removeItem(arr2, sizeTransactions, j);
						j = 0;
						sizeTransactions--;
					}
				}
				sizeViol--;
				i = 0;
				removeItem(arr, sizeViol, i);
			}
		}
		if (sizeViol == 0)
			cout << "He has'nt violations";
		else {
			cout << "amount viol - " << sizeViol << endl;
			for (int i = 0; i < sizeViol; i++) {
				cout << "#" << i + 1 << endl;
				arr[i].showViolation();
			}
			cout << "========================="<<endl;
		}
	}
	void fillDriver() {
		cout << "input name -";
		cin.getline(name, 100);
		cout << "input Car nubmer - ";
		cin >> carNumber;
	}
	void addViolation()
	{
		Violation obj;
		cout << "\nur new violation - ";

		obj.fillViolation();
		addItemBack(arr, sizeViol, obj);
	}
	void newTransaction()
	{
		cancelViol a;
		cout << "Your new transaction - ";
		a.NewTransaction();
		addItemBack(arr2, sizeTransactions, a);
	}
};