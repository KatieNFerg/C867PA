#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;

class Student
{
public:
	const static int daysCompleteCourseArray = 30;
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysCompleteCourseArray];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student();

	string getId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	DegreeProgram getDegreeProgram();

	void setId(string Id);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDays(int days[]);
	void setDegreeProgram(DegreeProgram dp);

	static void printHeader();

	void print();

};
