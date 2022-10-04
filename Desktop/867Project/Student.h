#pragma once
#include <string>
#include "Degree.h"
using namespace std;

class
	Student {


public:

	const static int daysRemainingSize = 3;
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysRemainingArray[], Degree d);

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysRemaining();
	virtual Degree getDegreeType(); // = 0;

	//setters
	void setStudentID(string ID);
	void setFirstName(string first);
	void setLastName(string last);
	void setEmailAddress(string email);
	void setAge(int age);
	void setDaysRemaining(int days[]);
	virtual void setDegreeType(Degree d); // = 0;
	virtual void print(); // = 0;

	~Student();


protected:


	string studentID;
	int age;
	int* daysRemainingArray;
	string firstName;
	string lastName;
	string emailAddress;
	Degree degree;


};