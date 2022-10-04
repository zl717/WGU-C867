
#include <iostream>
#include <string>
#include "Degree.h"
#include "NetworkingStudent.h"


NetworkStudent::NetworkStudent(){

	setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemainingArray[], Degree d) {
	setDegreeType(NETWORK);
}

Degree NetworkStudent::getDegreeType()
{
	return NETWORK;
}

void NetworkStudent::setDegreeType(Degree d) {
	d = NETWORK;
}

void NetworkStudent::print() {

	this->Student::print();
	cout << "Network" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}

