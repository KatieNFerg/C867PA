// C867PA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <array>
using namespace std;

int main()
{
    cout <<"Course Title: C867 - Scripting and Programming Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011630409" << endl;
    cout << "Student Name: Katie Ketcherside" << endl;
    cout << "  " << endl;

    const string studentData[] =
    {
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Katie,Ketcherside,kketc20@wgu.edu,27,42,30,30,SOFTWARE"
    };
    
    Roster* classRoster = new Roster(5);
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };
    cout << "Displaying all students: " << endl;
    classRoster->printAll();
 
    cout << "Displaying students with invalid emails" << endl;
    classRoster->printInvalidEmails();

    for (int i = 0; i < 5; i++)
    {
        cout << "Displaying average days: " << endl;
        classRoster->printAverageDaysInCourse(classRoster->GetStudentId(i));
    }

        cout << "Displaying by degree program: " << endl;
        classRoster->printByDegreeProgram(SOFTWARE);
    
    

 

    cout << "Removing student with Id A3" << endl;
    classRoster->remove("A3");
    
    classRoster->printAll();

    classRoster->remove("A3");

    classRoster->~Roster();
    delete classRoster;
   
}
