
#include "stdafx.h"
#include "EmployeeLinkedList.h"
#include <iostream>

void displayMenu();

int main()
{
	employeeList employeeList;
	char option;
	int dept=0;
	addEmployees7(employeeList);
	addEmployees6(employeeList);
	addEmployees5(employeeList);
	addEmployees4(employeeList);
	addEmployees3(employeeList);
	addEmployees2(employeeList);
	addEmployees(employeeList);
	system("CLS");
	cout << "\t|| EMPLOYEE STAFF DATABASE - LINKEDLIST ||\n\n";
	do
	{
		displayMenu();
		cout << "\nEnter your choice: (1-9): ";
		cin >> option;
		cout << "\n";
		switch (option)
		{
		case '1':	employeeList.displayEmployees();
			break;
		case '2':	insertEmployee(employeeList);
			break;
		case '3':	employeeList.removeEmployee(1);
			break;
		case '4':	employeeList.changeEmployeeLevel(1);
			break;
		case '5':	showManager(employeeList,1);
			break;
		case '6':	showStaff(employeeList,1);
			break;
		case '7':   employeeList.showMembersUnderManager(); 
			break;
		case '8':	employeeList.showAllHourlyRates();
			break;
		case '9':	break;
		default:	cout << "\n\t\t\t*** Invalid option! ***\n\n";
		}
		if (option != '9')
			system("pause");
	} while (option != '9');
	cout << "\n";

	return 0;
}

void displayMenu()
{
	cout << "\n1.	List all Employees";
	cout << "\n2.	Add an Employee (Manager or Staff Member)";
	cout << "\n3.	Remove an Employee";
	cout << "\n4.	Change a Staff Member's department";
	cout << "\n5.	Display a Manager's details";
	cout << "\n6.	Display a Staff Member's details";
	cout << "\n7.	List all Staff Members under a specified Manager";
	cout << "\n8.	Display hourly pay rates and wages of all Staff Members";
	cout << "\n9.	Quit";
}

