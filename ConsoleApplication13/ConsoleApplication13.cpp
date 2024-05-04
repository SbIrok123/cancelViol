
#include <iostream>
#include "Date.h"
#include "Violation.h"
#include "Driver.h"
using namespace std;
int main()
{
    /*Violation vasya;
    vasya.fillViolation();
    
    vasya.showViolation();*/

    //Driver Vasya;
    //Vasya.fillDriver();
    //Vasya.showDrive();
    //cout << "\n------------------------\n";
    //Vasya.addViolation();
    //Vasya.addViolation();
    //Vasya.showDrive();
    int _3month = 0;
    int NDrivers = 4;
    Driver* drivers = new Driver[NDrivers]{
        {"Vasya","AX1234XA",0,0,nullptr,nullptr},
        {"Katya","AX7777AX",0,0,nullptr,nullptr},
        {"Vika","AX1233XA",2,0,new Violation[2]{
            {{1,1,2024},"speed",15000},
            {{11,4,2024},"red",199},
    },nullptr},
        {"Olena","AX1233XA",3,3,new Violation[3]{
            {{1,2,2024},"speed",15000},
            {{15,11,2024},"Yellow",10},
            {{21,11,2024},"red",199}},
        new cancelViol[3]{
            {{15,11,2024},6.5},
            {{15,11,2024},3.5},
            {{1,2,2024},15000}
        }
    } };
    Driver obj;
    char text[100] = "";
    int id = -1;
    int menu = 0;
    Date a, b;
    do {
        cout << "--------------------\n";
        cout << "|       MENU       |\n";
        cout << "--------------------\n";
        cout << "1.Show all drivers\n";
        cout << "2.Add new driver\n";
        cout << "3.Show info by number\n";
        cout << "4.Add a violation\n";
        cout << "5.Find Violences by date\n";
        cout << "6.Add transaction by number\n";
        cout << "--------------------\n";
        cout << "0.Exit\n";
        cout << "--------------------\n";
        cout << " >>> "; cin >> menu;
        switch (menu)
        {
        case (1) :
            for (int i = 0; i < NDrivers; i++)
            {
                cout << "#" << i + 1 << " "
                    << drivers[i].carNumber << " "
                    << drivers[i].name << " "<<endl;
            }
            break;
        case (2):
            cin.ignore();
            obj.fillDriver();
            addItemBack(drivers, NDrivers, obj);
            break;
        case 3:
            cout << "input Car Number - ";
            cin >> text;
            for (int i = 0; i < NDrivers; i++)
            {
                if (strcmp(text, drivers[i].carNumber) == 0) {
                    id = i;
                    break;
                }
            }
            if (id == -1) cout << "not found";
            else drivers[id].showDrive();
            break;
        case 4:
            cout << "input Car Number - ";
            cin >> text;
            for (int i = 0; i < NDrivers; i++)
            {
                if (strcmp(text, drivers[i].carNumber) == 0) {
                    id = i;
                    break;
                }
            }
            if (id != -1) drivers[id].addViolation();
            else
            {
                cout << "No exist numbers";
            }
        case 5:
            cout << "from - ";
            cin >> a.day >> a.month >> a.year;
            cout << "to - ";
            cin >> b.day >> b.month >> b.year;
            for (int i = 0; i < NDrivers; i++)
            {
                for (int j = 0; j < drivers[i].sizeViol;j++) {
                    if (strcmp(drivers[i].arr[j].date.toString("%Y-%m-%d"), a.toString("%Y-%m-%d")) >= 0 && strcmp(drivers[i].arr[j].date.toString("%Y-%m-%d"), b.toString("%Y-%m-%d")) <= 0) {
                        cout << "name : " << drivers[i].name << endl;
                        drivers[i].arr[j].showViolation();
                    }
                }
            }
        case 6:
            cout << "input Car Number - ";
            cin >> text;
            for (int i = 0; i < NDrivers; i++)
            {
                if (strcmp(text, drivers[i].carNumber) == 0) {
                    id = i;
                    break;
                }
            }
            if (id != -1) drivers[id].newTransaction();
            else
            {
                cout << "No exist numbers";
            }

        default:
            break;
        }
    } while (menu != 0);
    return 0;
}
