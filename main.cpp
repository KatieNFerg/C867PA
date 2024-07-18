// C867PA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
using namespace std;
using std::endl;

int main()
{
    const string studentData[] =
    { 
    "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Katie,Ketcherside,kketc20@wgu.edu,27,42,SOFTWARE" 
    };
    const int numStudents = 5;
    Main main;
    
    for (int i = 0; i < numStudents; i++) main.parse(studentData[i]);
    cout << "Displaying all students: " << std::endl;
    main.printAll();