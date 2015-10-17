#include "stdafx.h"
#include <string>
#include <iomanip>
#include <iostream>
#include "EmployeeLinkedList.h"

using namespace std;

employeeList::employeeList()
{
	headPtr = NULL;
}

void employeeList::newEmployee(employeeNode*& newNode)
{
	newNode->nextNode = headPtr;
	headPtr = newNode;
}

employeeNode* employeeList::findManager(int empNumber)
{
	employeeNode* employeeNodePtr = headPtr;
	Manager* ManagerPtr;
	bool found = false;

	while ((employeeNodePtr != NULL) && !found)
	{
		if (employeeNodePtr->employeePtr->getEmpNo() == empNumber)
		{
			ManagerPtr = (Manager*)(employeeNodePtr->employeePtr);
			for (int i = 0; i < 7; i++)
			{
				if (ManagerPtr->getEmpNo() == i )
						return employeeNodePtr;
			}
		}
		employeeNodePtr = employeeNodePtr->nextNode;
	}
	return NULL;
}

employeeNode* employeeList::findStaff(int empNumber)
{
	employeeNode* employeeNodePtr = headPtr;
	Staff* StaffPtr;
	bool found = false;

	while ((employeeNodePtr != NULL) && !found)
	{
		if (employeeNodePtr->employeePtr->getEmpNo() == empNumber)
		{
			StaffPtr = (Staff*)(employeeNodePtr->employeePtr);
			for (int i = 0; i < 11; i++)
			{
				if (StaffPtr->getEmpNo() == i)
					return employeeNodePtr;
			}
		}
		employeeNodePtr = employeeNodePtr->nextNode;
	}
	return NULL;
}

bool employeeList::findName(string name)
{
	employeeNode* employeeNodePtr = headPtr;
	Staff* StaffPtr;
	bool found = false;

	while ((employeeNodePtr != NULL) && !found)
	{
		if (employeeNodePtr->employeePtr->getName() == name)
		{
			StaffPtr = (Staff*)(employeeNodePtr->employeePtr);
			for (int i = 0; i < 11; i++)
			{
				if (StaffPtr->getName() == name)
					return true;
			}
		}
		employeeNodePtr = employeeNodePtr->nextNode;
	}
	return false;
}

void employeeList::displayEmployees()
{
if (headPtr == NULL)
	{
		cout << "\n\t\t***\a List empty! ***\n\n";
		return;
	}
	employeeNode* currentNode = headPtr;
	Manager* managerPtr = NULL;
	Staff* staffPtr = NULL;

	cout << "\n|Department - \tName - \t\tStartDate - \tEmployee Number |\n\n";
	do
	{
		if (currentNode->employeeLevel == 'm')
		{
			managerPtr = (Manager*)(currentNode->employeePtr);
			 managerPtr->getDept();
					cout << "   Manager";		
		}
		else
		{
			staffPtr = (Staff*)(currentNode->employeePtr);
			 staffPtr->getDept();
				 cout << "    Staff";
		}
		cout << "\t" << currentNode->employeePtr->getName() << "\t";
		cout << currentNode->employeePtr->getStartDate() << "\t";
		cout << currentNode->employeePtr->getEmpNo() << "\n";
		currentNode = currentNode->nextNode;
	} while (currentNode != NULL);
	cout << "\n\n";
}

void employeeList::showMembersUnderManager()
{		
	int empNumber = 0;
	int managerDept;
	string managerName;
	employeeNode* currentNode = headPtr;
	employeeNode* currentNode1 = headPtr;
	cout << "Enter Employee Number for Manager: ";
	cin >> empNumber;
	cout << "\n";
	do{
		if (currentNode->employeePtr->getEmpNo() == empNumber)
		{	//Manager - display 
			cout << "\tManager:\n\t" << currentNode->employeePtr->getName() << "\t";
			cout << currentNode->employeePtr->getStartDate() << "\t";
			cout << currentNode->employeePtr->getEmpNo() << "\n\n";

			managerDept = currentNode->employeePtr->getDept();
			managerName = currentNode->employeePtr->getName();
			//Staff - display 
			cout << "\tStaff: \n";
			do
			{
				if (currentNode1->employeePtr->getDept()
					== managerDept && (currentNode1->employeePtr->getName() != managerName))
				{
					cout << "\t" << currentNode1->employeePtr->getName() << "\t";
					cout << currentNode1->employeePtr->getStartDate() << "\t";
					cout << currentNode1->employeePtr->getEmpNo() << "\n";
				}
					currentNode1 = currentNode1->nextNode;
			} while (currentNode1->nextNode != NULL);
			if (currentNode1->employeePtr->getDept()
				== managerDept && (currentNode1->employeePtr->getName() != managerName))
			{
				cout << "\t" << currentNode1->employeePtr->getName() << "\t";
				cout << currentNode1->employeePtr->getStartDate() << "\t";
				cout << currentNode1->employeePtr->getEmpNo() << "\n";
			}
		}	
		else
		{ 
			currentNode = currentNode->nextNode; 
		}
	} while (currentNode1->nextNode != NULL);
	cout << "\n";
}

void employeeList::showAllHourlyRates()
{
	employeeNode* currentNode = headPtr;
	Staff* StaffPtr;
	
	StaffPtr = (Staff*)(currentNode->employeePtr);
	cout << "|\tName -\t\tStartDate -\tEmployee Number - Salary - HourlyWage |\n\n";
	if (StaffPtr->getEmpNo() == currentNode->employeePtr->getEmpNo())
	{
		do {
			if (currentNode->employeeLevel == 's')
			{
				cout << "\t" << currentNode->employeePtr->getName() << "\t";
				cout << currentNode->employeePtr->getStartDate() << "\t\t";
				cout << currentNode->employeePtr->getEmpNo() << "\t";
				cout << setprecision(2) << fixed << StaffPtr->getWage() << "\t\t";
				cout << setprecision(2) << fixed << StaffPtr->getRate() << "\n";
			}

			currentNode = currentNode->nextNode;
			StaffPtr = (Staff*)(currentNode->employeePtr);

		} while (currentNode->nextNode != NULL);
		cout << "\t" << currentNode->employeePtr->getName() << "\t";
		cout << currentNode->employeePtr->getStartDate() << "\t\t";
		cout << currentNode->employeePtr->getEmpNo() << "\t";
		cout << setprecision(2) << fixed << StaffPtr->getWage() << "\t\t";
		cout << setprecision(2) << fixed << StaffPtr->getRate() << "\n";
	}
	else StaffPtr = (Staff*)(currentNode->nextNode->employeePtr);
}

employeeList::~employeeList()
{
	employeeNode* oldHead;
	oldHead = headPtr;
	do {
		if (headPtr->employeePtr->getEmpNo() == NULL)
		{
			cout << "\nNo Employees in system\n";
		}
		else
			if (headPtr->employeeLevel == 'm')
			{
				Manager* managerPtr = (Manager*)(headPtr->employeePtr);
				delete managerPtr;
			}
			else
			{
				Staff* staffptr = (Staff*)(headPtr->employeePtr);
				delete staffptr;
			}
		headPtr = headPtr->nextNode;
	} while (headPtr->nextNode != NULL);

	Staff* staffptr = (Staff*)(headPtr->employeePtr);
	delete staffptr;
	
	delete oldHead;
	system("pause");
}

void addEmployees(employeeList& employeeList)
{
	string firstname = "Nikhil";
	string surname = "Vedi";
	string name = (firstname + " " + surname);
	string startDate1 = "01/01/13";
	int salary = 40000;
	int empNumber1 = 1;
	int dept1 = 1;

	Employee* newEmployee =
	new Manager(salary,name, startDate1, empNumber1, dept1);
		
		employeeNode* newNode = new employeeNode;
		newNode->employeePtr = newEmployee;
		newNode->employeeLevel = 'm';
		employeeList.newEmployee(newNode);

}

void addEmployees2(employeeList& employeeList)
{
	string firstname = "John";
	string surname = "Smith";
	string name = (firstname + " " + surname);
	string startDate = "01/11/14";
	int salary = 29000;
	int empNumber = 2;
	int dept = 2;

	Employee* newEmployee =
		new Manager(salary,name, startDate, empNumber, dept);

	employeeNode* newNode = new employeeNode;
	newNode->employeePtr = newEmployee;
	newNode->employeeLevel = 'm';
	employeeList.newEmployee(newNode);

}

void addEmployees3(employeeList& employeeList)
{
	string firstname = "Capri";
	string surname = "Hero";
	string name = (firstname + " " + surname);
	string startDate = "21/04/14";
	int empNumber = 3;
	int dept = 1;
	double hourlyRate = 6.67;
	int HoursPerWeek = 30;

	Employee* newEmployee =
		new Staff(HoursPerWeek, hourlyRate, name, 
		startDate, empNumber, dept);

	employeeNode* newNode = new employeeNode;
	newNode->employeePtr = newEmployee;
	newNode->employeeLevel = 's';
	employeeList.newEmployee(newNode);
}

void addEmployees4(employeeList& employeeList)
{
	string firstname = "Ben";
	string surname = "Shaw";
	string name = (firstname + " " + surname);
	string startDate = "11/09/14";
	int empNumber = 4;
	int dept = 1;
	double hourlyRate = 7.58;
	int HoursPerWeek = 20;

	Employee* newEmployee =
		new Staff(HoursPerWeek, hourlyRate, name,
		startDate, empNumber, dept);

	employeeNode* newNode3 = new employeeNode;
	newNode3->employeePtr = newEmployee;
	newNode3->employeeLevel = 's';
	employeeList.newEmployee(newNode3);
}

void addEmployees5(employeeList& employeeList)
{
	string firstname = "Daniel";
	string surname = "Peacock";
	string name = (firstname + " " + surname);
	string startDate = "17/04/13";
int empNumber = 5;
int dept = 2;
double hourlyRate = 8.51;
int HoursPerWeek = 26;

Employee* newEmployee =
new Staff(HoursPerWeek, hourlyRate, name, 
startDate, empNumber, dept);

employeeNode* newNode3 = new employeeNode;
newNode3->employeePtr = newEmployee;
newNode3->employeeLevel = 's';
employeeList.newEmployee(newNode3);
}

void addEmployees6(employeeList& employeeList)
{
	string firstname = "Tom";
	string surname = "Freer";
	string name = (firstname + " " + surname);
	string startDate = "03/19/12";
	int empNumber = 6;
	int dept = 1;
	double hourlyRate = 9.67;
	int HoursPerWeek = 10;

	Employee* newEmployee =
		new Staff(HoursPerWeek, hourlyRate, name,
		startDate, empNumber, dept);

	employeeNode* newNode3 = new employeeNode;
	newNode3->employeePtr = newEmployee;
	newNode3->employeeLevel = 's';
	employeeList.newEmployee(newNode3);
}

void addEmployees7(employeeList& employeeList)
{
	string firstname = "Joe";
	string surname = "Alcock";
	string name = (firstname + " " + surname);
	string startDate = "25/12/13";
	int empNumber = 7;
	int dept = 2;
	double hourlyRate = 7.50;
	int HoursPerWeek = 40;

	Employee* newEmployee =
		new Staff(HoursPerWeek, hourlyRate, name,
		startDate, empNumber, dept);

	employeeNode* newNode3 = new employeeNode;
	newNode3->employeePtr = newEmployee;
	newNode3->employeeLevel = 's';
	employeeList.newEmployee(newNode3);
}

void insertEmployee(employeeList& employeeList)
{
	int dept;
	string firstname;
	string surname;
	string startDate;
	int empNumber;
	double hourlyRate;
	int hoursPerWeek;
	int salary = 0;
	string level;
	unsigned char pound = 156;

	cout << "Manager or Staff?\n";
	cin >> level;

	if (level == "manager")
	{
		cout << "\nEnter Department: (1/2)\n";
		cin >> dept;

		cout << "\nEnter FullName: (FirstName/Surname)\n";
		cin >> firstname;
		cin >> surname;
		string name = (firstname + " " + surname);
		if (employeeList.findName(name) == true)
		{
			cin.ignore();
			cout << "ERROR! Employee Already Present..";
			cout << "Terminating Entry!\n";
			return;
		}

		cout << "\nEnter their Start Date: (DD/MM/YY)\n";
		cin >> startDate;

		cout << "\nEnter their Employee Number: \n";
		cin >> empNumber;
		while (empNumber <= 7)		
		{
			cin.ignore();
			cout << "ERROR! Employee Number Already Present..";
			cout << "Terminating Entry!\n";
			return;
		}

		cout << "\nEnter their Yearly Salary: \n ";
		cout << pound;
		cin >> salary;

		Employee* newEmployee =
			new Manager(salary, name, startDate, empNumber, dept);

		employeeNode* newNode = new employeeNode;
		newNode->employeePtr = newEmployee;
		newNode->employeeLevel = 'm';
		employeeList.newEmployee(newNode);
	}
	else
		if (level == "staff")
		{
		cout << "\nEnter Department: (1/2)\n";
		cin >> dept;

		cout << "\nEnter FullName: (FirstName/Surname)\n";
		cin >> firstname;
		cin >> surname;
		string name = (firstname + " " + surname);
		if ( employeeList.findName(name) == true)
		{
			cin.ignore();
			cout << "ERROR! Employee Already Present..";
			cout << "Terminating Entry!\n";
			return;
		}

		cout << "\nEnter their Start Date: (DD/MM/YY)\n";
		cin >> startDate;

		cout << "\nEnter their Employee Number: \n";
		cin >> empNumber;
		while (empNumber <= 7)
		{
			cin.ignore();
			cout << "ERROR! Employee Number Already Present..";
			cout << "Terminating Entry!\n";
			return;
		}

		cout << "\nEnter their Hourly Rate: \n ";
		cout << pound;
		cin >> hourlyRate;

		cout << "\nEnter their Hours per Week: \n";
		cin >> hoursPerWeek;

		Employee* newEmployee =
			new Staff(hoursPerWeek, hourlyRate, name, 
			startDate, empNumber, dept);

		employeeNode* newNode = new employeeNode;
		newNode->employeePtr = newEmployee;
		newNode->employeeLevel = 's';
		employeeList.newEmployee(newNode);
		}
		else
		{
		cout << "\n\tNo such Employee level, Try Again!";
		}
	cout << "\n\n";
}

void employeeList::changeEmployeeLevel(int empNumber)
{
	employeeNode* employeeNodePtr;
	cout << "Enter Employee Number: ";
	cin >> empNumber;
	employeeNodePtr = findStaff(empNumber);
	int level = 1;
	level = employeeNodePtr->employeePtr->getDept();
	int newDept;
	if (level == 2)
	{
		cout << "Which Department? (1/2)";
		cin >> newDept;
		if (newDept < 3)
		{
			employeeNodePtr->employeePtr->setDept(newDept);
			cout << "Transfer Completed!";
		}
		else
		{
			cin.ignore();
			cout << "ERROR! No such Department!\n";
			return;
		}
	}
	else if (level == 1)
	{
		cout << "Which Department? (1/2)\n:";
		cin >> newDept;
		if (newDept < 3)
		{
			employeeNodePtr->employeePtr->setDept(newDept);
			cout << "Transfer Completed!";
		}
		else
		{
			cin.ignore();
			cout << "ERROR! No such Department!\n";
			return;
		}
	}
	 else cout << "\nNo such Department! \n\n";
}

void showManager(employeeList& employeeList, int empNumber)
{	
	employeeNode* employeeNodePtr;
	Manager* managerPtr;
	unsigned char pound = 156;
	cout << "Enter Employee Number: ";
	cin >> empNumber;
	cout << "\nManager: ";
	employeeNodePtr = employeeList.findManager(empNumber);
	if (employeeNodePtr == NULL)
		cout << " \n\n\t\t NO MANAGERS! ";
	else
	{
		managerPtr = (Manager*)(employeeNodePtr->employeePtr);
		cout << employeeNodePtr->employeePtr->getName() << "\n";
		cout << "Department: ";
		cout << employeeNodePtr->employeePtr->getDept() << "\n";
		cout << "Salary: ";
		cout << pound << managerPtr->getSalary() << "\n";
	}
}

void showStaff(employeeList& employeeList, int empNumber)
{	
	employeeNode* employeeNodePtr;
	Staff* staffPtr;
	unsigned char pound = 156;
	cout << "Enter Employee Number: ";
	cin >> empNumber;
	cout << "\nStaff: ";
	employeeNodePtr = employeeList.findStaff(empNumber);
	if (employeeNodePtr == NULL)
		cout << " \n\n\t\t NO STAFF! ";
	else
	{
		staffPtr = (Staff*)(employeeNodePtr->employeePtr);
		cout << employeeNodePtr->employeePtr->getName() << "\n";
		cout << "Department: ";
		cout << employeeNodePtr->employeePtr->getDept() << "\n";
		cout << "Wage: ";
		cout << pound << setprecision(2) << fixed <<
			staffPtr->getWage() << "\n";
	}
}

void employeeList::removeEmployee(int empNumber)
{
	employeeNode* currentNode;
	currentNode = headPtr;
	cout << "Enter the Employee Number to remove \nNumber: ";
	cin >> empNumber;
	int newEmp = (empNumber - 1);
	currentNode = findStaff(newEmp);
	if (currentNode == NULL)
	{
		cout << "No such Employee!\n";
		return;
	}
	do{
		if (currentNode->employeePtr->getEmpNo()
			== newEmp && (currentNode->employeeLevel == 'm'))
		{
			Manager* managerPtr = (Manager*)(currentNode->employeePtr);
			currentNode->nextNode = currentNode->nextNode->nextNode;
		}
		else
			if (currentNode->employeePtr->getEmpNo()
				== newEmp && (currentNode->employeeLevel == 's'))
			{
			Staff* staffPtr = (Staff*)(currentNode->employeePtr);
			currentNode->nextNode = currentNode->nextNode->nextNode;
			}
		currentNode = currentNode->nextNode;
	} while (currentNode != NULL);
	if (currentNode == NULL)
	{
		cout << "\n\nEmployee with Number: " << empNumber << " Removed! \n\n";
	}
}



