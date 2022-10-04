#include <iostream>
#include "SecurityStudent.h"
using std::cout;

SecurityStudent::SecurityStudent()
{
	setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int* daysRemainingArray[], Degree d)
{
	setDegreeType(SECURITY);
}

Degree SecurityStudent::getDegreeType()
{
	return SECURITY;
}

void SecurityStudent::setDegreeType(Degree d)
{
	this->degree = SECURITY;
}

void SecurityStudent::print()
{
	this->Student::print();
	cout << "Security" << "\n";
}

SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}