#include "roster.h"
#include "student.h"
#include "degree.h"
void Roster::parse(string studentdata)
{
	DegreeProgram dp = SECURITY;
	if (studentdata.at(0) == 'SO') dp = SOFTWARE;
	else if (studentdata.at(0) == 'N') dp = NETWORK;

	int rhs = studentdata.find(",");
	string sId = studentdata.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string fin = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string lan = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string ema = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int sAge = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d1 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d2 = stod(studentdata.substr(lhs, rhs - lhs));
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int d3 = stod(studentdata.substr(lhs, rhs - lhs));

	add(sId, fin, lan, ema, sAge, d1, d2, d3, dp);
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	
	int parr[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentId, firstName, lastName, emailAddress, age, parr, degreeProgram);
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getId(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getDays()[0]; cout << '\t';
		cout << classRosterArray[i]->getDays()[1]; cout << '\t';
		cout << classRosterArray[i]->getDays()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string sEmailAddress = (classRosterArray[i]->getEmailAddress());
		if (sEmailAddress.find('@') == string::npos || (sEmailAddress.find('.') == string::npos && sEmailAddress.find(' ') == string::npos))
		{
			any = true;
			cout << sEmailAddress << ": " << classRosterArray[i]->getFirstName() << std::endl;
		}
	}
	if (!any) cout << "NONE" << std::endl;
}

void Roster::printAverageDaysInCourse(string studentId)
{
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getId() << ": ";
		cout << (classRosterArray[i]->getDays()[0]
			+ classRosterArray[i]->getDays()[1]
			+ classRosterArray[i]->getDays()[2]) / 3 << std::endl;
	}
	cout << std::endl;
}

void Roster::remove(string studentId)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getId() == studentId)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;

			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentId << " removed from roster." << std::endl << std::endl;
		this->printAll();
	}
	else cout << studentId << " not found." << std::endl << std::endl;
}

Roster::~Roster()
{
	cout << "Destructor called" << std::endl << std::endl;
	for(int i = 0; i < numStudents; i++)
	{
		cout << "Destroying student " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}