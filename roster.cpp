#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <array>

using namespace std;
Roster::Roster(int classSize)
{
	for (int i = 0; i < classSize; i++) {
		classRosterArray[i] = nullptr;
	}
	this->classSize = classSize;
	this->index = 0;
	for (int i = 0; i < classSize; i++) {
		this->classRosterArray[i] = new Student;
	}
	return;
}

string Roster::GetStudentId(int index)
{
	string sId = classRosterArray[index]->getStudentId();
	return sId;
}
void Roster::parse(string studentData)
{
	string sId, firstName, lastName, emailAddress;
	int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;

	if (index < classSize) {
		classRosterArray[index] = new Student();

		int i = studentData.find(",");
		sId = studentData.substr(0, i);
		classRosterArray[index]->setId(sId);

		int d = i + 1;
		i = studentData.find(",", d);
		firstName = studentData.substr(d, i - d);
		classRosterArray[index]->setFirstName(firstName);

		d = i + 1;
		i = studentData.find(",", d);
		lastName = studentData.substr(d, i - d);
		classRosterArray[index]->setLastName(lastName);

		d = i + 1;
		i = studentData.find(",", d);
		emailAddress = studentData.substr(d, i - d);
		classRosterArray[index]->setEmailAddress(emailAddress);

		d = i + 1;
		i = studentData.find(",", d);
		studentAge = stoi(studentData.substr(d, i - d));
		classRosterArray[index]->setAge(studentAge);

		d = i + 1;
		i = studentData.find(",", d);
		daysInCourse1 = stoi(studentData.substr(d, i - d));

		d = i + 1;
		i = studentData.find(",", d);
		daysInCourse2 = stoi(studentData.substr(d, i - d));

		d = i + 1;
		i = studentData.find(",", d);
		daysInCourse3 = stoi(studentData.substr(d, i - d));
		classRosterArray[index]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

		d = i + 1;
		i = studentData.find(",", d);
		string type = studentData.substr(d, i - d);
		if (type == "SOFTWARE") {
			classRosterArray[index]->setDegreeProgram(DegreeProgram::SOFTWARE);
		}
		else if (type == "SECURITY") {
			classRosterArray[index]->setDegreeProgram(DegreeProgram::SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[index]->setDegreeProgram(DegreeProgram::NETWORK);
		}
		else {
			cout << "Invalid degree program." << endl;
		}
		index++;
	}
	return;
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[classSize] = new Student(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
};
	
void Roster::remove(string studentId)
{
	bool success = false;
	for (int i = 0; i < classSize; i++)
	{
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (studentId == classRosterArray[i]->getStudentId())
		{
			classRosterArray[i] = nullptr;
			success = true;
			break;
		}
	}
	if (success)
	{
		cout << "Student with ID " << studentId << " not found." << endl;
	}
	else if (!success) {
		cout << "Student " << studentId << " removed." << endl;
	}
	return;
}

void Roster::printAll()
{
	cout << "All current students: " << endl;
	for(int i = 0; i < classSize; i++)
	{
		if (classRosterArray[i] == nullptr)
		{
			continue;
		}
		else {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
	return;
	
}
void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] != nullptr) {
		if (studentId == classRosterArray[i]->getStudentId()) {
			int averageDays = (classRosterArray[i]->getDaysInCourse()[0] + 
							classRosterArray[i]->getDaysInCourse()[1] +
							classRosterArray[i]->getDaysInCourse()[2]) / 3;
			cout << "Average days in course for student ID " << studentId << ": " << averageDays << endl;
		}
	}
}
	return;
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < classSize; i++)
	{
		string sEmailAddress = classRosterArray[i]->getEmailAddress();
		if (sEmailAddress.find('@') == string::npos || (sEmailAddress.find('.') == string::npos && sEmailAddress.find(' ') != string::npos))
		{
			cout << "Invalid email address: " << sEmailAddress << ": " << classRosterArray[i]->getStudentId() << " is invalid." << endl;
		}
	}
	cout << endl;
	return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	string degreeString = "";
	switch (degreeProgram) {
	case DegreeProgram::SECURITY:
		degreeString = "SECURITY";
		break;
		case DegreeProgram::NETWORK:
			degreeString = "NETWORK";
		break;
		case DegreeProgram::SOFTWARE:
			degreeString = "SOFTWARE";
			break;
			default:
				cout << "Error" << endl;
				return;
	}
	cout << "Students in the " << degreeString << " program: " << endl;
	int numStudents = 0;
	for (int i = 0; i < classSize; i++)
	{
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			classRosterArray[i]->print();
			numStudents++;
		}
	}
	if (numStudents == 0)
	{
		cout << "No students found in the " << degreeString << " program." << endl;
	}
	
}



			

Roster::~Roster()
{
	for (int i = 0; i < 5; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};

}