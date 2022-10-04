#pragma once

#include <string>
#include "Student.h"
using namespace std;

const int numStudents = 5;

string studentData[] =
{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",

"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",

"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",

"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

"A5,Zach,Landreth,zlandre@wgu.edu,20,17,19,21,SOFTWARE" };

class
	Roster {

public:

	void add(string row);

	int lastIndex;									//
	int capacity;									//
	Student **classRosterArray;						//students
	Roster();										//default constructor
	Roster(int capacity);							//constructor which sets capacity
	void printAll();								//displays the complete list of students
	void remove(string studentID);					//remove student by ID
	void printAverageDaysInCourse(string studentID);//shows the average days remaining in a course for a specified student
	void printInvalidEmails();						//displays emails with invalid traits
	void printByDegreeProgram(Degree d);			//all students in specified degree program
	~Roster();										//destroy dynamically requested data

};