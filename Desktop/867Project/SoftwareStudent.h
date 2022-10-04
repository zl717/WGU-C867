#pragma once
#include "Student.h"
#include "Degree.h"

class
	SoftwareStudent : public Student {

public:
	SoftwareStudent();
	SoftwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemainingArray[], Degree d);

	Degree getDegreeType();
	void setDegreeType(Degree d);
	void print();

	~SoftwareStudent();
};