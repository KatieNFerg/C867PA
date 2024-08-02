#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

class Roster
{

public:
	Student* classRosterArray[5];
	Roster(int classSize);
	string GetStudentId(int index);
	void parse(string studentData);
	void remove(string studentId);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	int classSize;
	int index;
	void add(string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		int studentAge,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeProgram);
	~Roster();
};
#endif