#include "stdafx.h"
#include <string>
#include "Employee.h"
#include <iostream>
#include <iomanip>

using namespace std;

Employee::Employee(){}
Employee::Employee(string name,
	string startDate, int empNumber, int dept) 
{
	this->name = name;
	this->startDate = startDate;
	this->empNumber = empNumber;
	this->dept = dept;
}

string Employee::getName()
{
	return name;
}

string Employee::getStartDate()
{
	return startDate;
}

int  Employee::getEmpNo()
{
	return empNumber;
}

int Employee::getDept()
{
	return dept;
}

void Employee::setDept(int deptIn)
{
	dept = deptIn;
}

void Employee::setName(string nameIn)
{
	name = nameIn;
}

Employee::~Employee()
{
	cout << "\n Executing Employee destructor: ";
	cout << this->getEmpNo() << "\n";
}

Manager::Manager(){}
Manager::Manager(int salary,string name, 
	string startDate, int empNumber, int dept)
		:Employee(name, startDate, empNumber, dept)
{
	this->salary = salary;
}

int Manager::getSalary()
{
	return salary;
}

void Manager::setSalary(int salaryIn)
{
	salary = salaryIn;
}

Manager::~Manager()
{
	cout << "\n Executing Manager destructor - ";
	cout << "Manager: " << name << " Removed;";
}

Staff::Staff(){}
Staff::Staff(int hoursPerWeek, double hourlyRate,
	string name, string startDate, int empNumber, int dept)
	  :Employee(name, startDate, empNumber, dept) 
{
	this->hoursPerWeek = hoursPerWeek;
	this->hourlyRate = hourlyRate;
}

void Staff::setHours(int hoursPerWeekIn)
{
	hoursPerWeek = hoursPerWeekIn;
}

void Staff::setRate(double hourlyRateIn)
{
	hourlyRate = hourlyRateIn;
}

double Staff::getRate()
{
	return hourlyRate;
}

double Staff::getWage()
{
//wage will use hourly rate * hours per week 
	double wage;
	wage = (hourlyRate*hoursPerWeek);
	return wage;
}

Staff::~Staff()
{
	cout << "\n Executing Staff destructor - ";
	cout << "Staff: " << name << " Removed;";
}