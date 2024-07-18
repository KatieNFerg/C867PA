#include "student.h"
Student::Student()
{
	this->studentId = 0;
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysCompleteCourseArray; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(int studentId, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysCompleteCourseArray; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}
