#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "degree.h"
#include <string>
using namespace std;


class Student
{
private:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);


	void setId(string sId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int studentAge);
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeProgram);
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();

	DegreeProgram getDegreeProgram();
	void printId();
	void printFirstName();
	void printLastName();
	void printEmailAddress();
	void printAge();
	void printDaysToComplete();
	void printDegreeProgram();
	void print();

};
#endif
