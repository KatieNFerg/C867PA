#pragma once
#include "student.h"

class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	Student** getClassRosterArray();
	void parse(string row);
	void add(string sId,
		string sFirstName,
		string sLastName,
		string sEmailAddress,
		int sAge,
		int sdaysInCourse1,
		int sdaysInCourse2,
		int sdaysInCourse3,
		DegreeProgram dp);
	void printAll();
	void printAverageDaysInCourse(string studentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram dp);
	void remove(string studentId);
	~Roster();
};
