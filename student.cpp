#include "student.h"
Student::Student()
{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysCompleteCourseArray; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysCompleteCourseArray; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getId() { return this->studentId;  }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setId(string Id) { this->studentId = Id; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(int Days[])
{
	for (int i = 0; i < daysCompleteCourseArray; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void Student::printHeader()
{
	cout << "Output format: Id|FirstName|LastName|EmailAddress|Age|Days|Program\n";
}
void Student::print()
{
	cout << this->getId() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << ',';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
}

