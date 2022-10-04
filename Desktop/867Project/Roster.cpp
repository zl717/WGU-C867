
#include <iostream>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"
#include "SecurityStudent.h"
#include "SoftwareStudent.h"
#include "NetworkingStudent.h"




Roster::Roster(){

	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) {

	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = new Student* [capacity];
	
}

void Roster::printAll(){

	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}



void Roster::remove(string studentID)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID) 
		{

			//delete it
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
			cout << "Student " <<studentID << ": Removed" << endl;

			if (classRosterArray[i]->getStudentID().find(studentID) == std::string::npos)
				cout << "Student with ID: " << studentID << " not found" << endl;
			
		}

	}
}

void Roster::printAverageDaysInCourse(string studentID){

	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID) 
		{
			
			int* days = classRosterArray[i]->getDaysRemaining();
			cout << "Average days in course for student " << studentID << " is " << (days[0] + days[1] + days[2]) / 3<< "\n";
		}
	}
}

void Roster::printInvalidEmails(){

	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getEmailAddress().find("@") == std::string::npos)
			cout << "Invalid Email found : " << classRosterArray[i]->getEmailAddress() << endl;
		else if (classRosterArray[i]->getEmailAddress().find(".") == std::string::npos)
			cout << "Invalid Email found : " << classRosterArray[i]->getEmailAddress() << endl;
		else if (classRosterArray[i]->getEmailAddress().find(" ") != std::string::npos)
			cout << "Invalid Email found: " << classRosterArray[i]->getEmailAddress() << endl;
			
	}
	
}

void Roster::printByDegreeProgram(Degree d) {

	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeType() == d) this->classRosterArray[i]->print();
	}
}

Roster::~Roster(){
	
	for (int i = 0; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}



void Roster::add(string row){

	if (lastIndex < numStudents-1) {
		lastIndex++;
		int studentArray[Student::daysRemainingSize];
		
		if (row.find("SECURITY") != std::string::npos) {
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegreeType(SECURITY);
		}
		else if (row.find("SOFTWARE") != std::string::npos) { 
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
		}
		else if (row.find("NETWORK") != std::string::npos) {
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegreeType(NETWORK);

		}


		//ID
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));


		//first name
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//last name
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//email address
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		//days in class
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		studentArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		studentArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		studentArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set the days
		classRosterArray[lastIndex]->setDaysRemaining(studentArray);
	}
	
}




int main()
{

	cout << "Scripting and Programming - Applications - C867 \n";
	cout << "C++ \n";
	cout << "Student ID: #000849557 \n";
	cout << "Zachary Landreth \n \n";

	Roster* classRoster = new Roster(numStudents);
	//add students
	for (int i = 0; i < numStudents; i++)
	{
		classRoster->add(studentData[i]);
		
	}
	//classRoster->print_All();
	//classRoster->printInvalidEmails();
	//classRoster->remove("A5");
	//classRoster->printDaysInCourse("A5");
	//classRoster->printByBookType(NETWORK);


	classRoster->printAll();
	cout << "\n";
	classRoster->printInvalidEmails();
	cout << "\n";

	//loop through classRosterArray and for each element:
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());	
	}

	cout << "\n";
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "\n";
	classRoster->remove("A3");
	cout << "\n";
	classRoster->remove("A3");
	//expected: the above line should print a message saying such a student with this ID was not found.
	
	
	
}