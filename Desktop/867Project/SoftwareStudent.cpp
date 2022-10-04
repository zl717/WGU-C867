#include "SoftwareStudent.h"
#include <iostream>
#include <string>
#include "Degree.h"

SoftwareStudent::SoftwareStudent() {
	setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemainingArray[], Degree d) {
	setDegreeType(SOFTWARE);
}

Degree SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::setDegreeType(Degree d) {
	d = SOFTWARE;
}

void SoftwareStudent::print() {

	this->Student::print();
	cout << "Software" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}
