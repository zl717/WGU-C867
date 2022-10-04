#include "Student.h"
#include "Degree.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(){

	this->studentID = "N/A";
	this->firstName = "N/A";
	this->lastName= "N/A";
	this->emailAddress = "N/A";
	this->age = 0;
	this->daysRemainingArray = new int[daysRemainingSize];
	for (int i = 0; i < daysRemainingSize; i++) this->daysRemainingArray[i] = 0;

}

Student::Student(string ID, string first, string last, string email, int a, int daysRemainingArray[], Degree d){

	this->studentID = ID;
	this->firstName = first;
	this->lastName = last;
	this->emailAddress = email;
	this->age = a;
	this->daysRemainingArray = new int[daysRemainingSize];
	for (int i = 0; i < 3; i++) this->daysRemainingArray[i] = daysRemainingArray[i];

}


string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysRemaining()
{
	return daysRemainingArray;
}

Degree Student::getDegreeType()
{
	return Degree();
}

void Student::setStudentID(string ID){

	studentID = ID;
}

void Student::setFirstName(string first){

	firstName = first;
}

void Student::setLastName(string last){

	lastName = last;
}

void Student::setEmailAddress(string email){

	emailAddress = email;
}

void Student::setAge(int a){

	age = a;
}

void Student::setDaysRemaining(int daysRemainingArray[]){

	if (this->daysRemainingArray != nullptr) {
		delete[] this->daysRemainingArray;
		this->daysRemainingArray = nullptr;
	}
	this->daysRemainingArray = new int[daysRemainingSize];
	for (int i = 0; i < 3; i++)
		this->daysRemainingArray[i] = daysRemainingArray[i];
}

void Student::setDegreeType(Degree d){

}



void Student::print()
{
	
	cout << studentID << "	";
	cout << setw(10) << firstName << "	";
	cout << setw(10) << lastName << "	";
	cout << setw(22) << emailAddress << "	";
	cout << setw(10) << age << "	";
	cout << setw(10) << "{ " << daysRemainingArray[0] << ", " << daysRemainingArray[1] << ", " << daysRemainingArray[2] << " }	  ";
}

Student::~Student(){

	if (daysRemainingArray != nullptr) {
		delete[] daysRemainingArray;
		daysRemainingArray = nullptr;
		}
	
}