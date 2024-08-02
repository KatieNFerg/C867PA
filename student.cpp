#include <iostream>
#include "student.h"
#include "degree.h"
#include <string>
using namespace std;

Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
	this->degreeProgram;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

void Student::setId(string sId) {
	this->studentId = sId;

	return;

}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int studentAge) {
	this->age = studentAge;
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	for (int i = 0; i < 3; i++)
		this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

string Student::getStudentId() {
	return studentId;
}
string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getDaysInCourse() {
	return daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}
void Student::printId() {
	cout << studentId;
	return;
}
void Student::printFirstName() {
	cout << firstName << endl;
	return;
}
void Student::printLastName() {
	cout << lastName << endl;
	return;
}
void Student::printEmailAddress() {
	cout << emailAddress << endl;
	return;
}
void Student::printAge() {
	cout << age << endl;
	return;
}
void Student::printDaysToComplete() {
	cout << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << endl;
	return;
}

void Student::printDegreeProgram() {
	string degreeString;
	if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
		}
	cout << degreeString << endl;
	return;
}

void Student::print()
{
	string degreeString;
	if (degreeProgram == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else if (degreeProgram == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == SECURITY) {
		degreeString = "SECURITY";
	}
	else {
		degreeString = "Error";
	}
	cout << studentId
		<< "\tFirst Name: " << getFirstName()
		<< "\tLast Name: " << getLastName()
		<< "\tAge: " << getAge()
		<< "\tdaysInCourse: {" << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} Degree Program: " << degreeString << " " << endl;
	return;

}

