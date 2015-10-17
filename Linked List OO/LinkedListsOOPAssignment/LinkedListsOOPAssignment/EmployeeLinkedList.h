#include "stdafx.h"
#include <string>
#include "Employee.h"

using namespace std;

struct employeeNode
{
	Employee* employeePtr;
	char employeeLevel;
	employeeNode* nextNode;
};

class employeeList
{
private:
	employeeNode* headPtr;
public:
	employeeList();
	void newEmployee(employeeNode*& newNode);	
	bool findName(string);
	employeeNode* findManager(int);
	employeeNode* findStaff(int);
	void displayEmployees();
	void removeEmployee(int);
	void showMembersUnderManager();
	void showAllHourlyRates();
	void changeEmployeeLevel(int);
	virtual ~employeeList();
};

void showManager(employeeList&,int); 
void showStaff(employeeList&,int); 
void showAllHourlyRates(employeeList&);
void addEmployees(employeeList&);
void addEmployees2(employeeList&);
void addEmployees3(employeeList&);
void addEmployees4(employeeList&);
void addEmployees5(employeeList&);
void addEmployees6(employeeList&);
void addEmployees7(employeeList&);
void insertEmployee(employeeList&);
