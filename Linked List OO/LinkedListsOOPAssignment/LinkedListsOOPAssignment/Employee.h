#include "stdafx.h"
#include <string>

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
protected:
	string name;
	string startDate;
	int empNumber;
	int dept;

public:
	Employee();
	Employee(string, string, int, int);
	string getName();
	string getStartDate();
	int getEmpNo();
	int getDept();
	void setDept(int);
	void setName(string);
	virtual ~Employee();
};

class Manager : public Employee
{
private:
	int salary;

public:
	Manager();
	Manager(int,string, string, int, int);
	int getSalary();
	void setSalary(int);
	virtual ~Manager();
};

class Staff : public Employee
{
private:
	int hoursPerWeek;
	double hourlyRate;

public:
	Staff();
	Staff(int, double, string, string, int, int);
	void setHours(int);
	void setRate(double);
	double getWage();
	double getRate();
	virtual ~Staff();

};	
#endif