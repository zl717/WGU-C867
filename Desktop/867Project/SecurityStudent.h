#pragma once
#include "Degree.h"
#include "Student.h"
#include <string>

class
	SecurityStudent : public Student {

public:

	SecurityStudent();
	SecurityStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int *daysRemainingArray[], Degree d);


	Degree getDegreeType();
	void setDegreeType(Degree d);
	void print();

	~SecurityStudent();
};