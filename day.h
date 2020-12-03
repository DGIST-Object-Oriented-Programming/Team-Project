#pragma once
#include<iostream>
#include "subject.h"
#include "person.h"

#ifndef DAY
class Person;

class Day {
public:
	Day();
	Day(Person&);
	void Study(Subject&, Person&); 
	void Study(float, Subject&, Person&);

	void Sleep(Person&);
	void Sleep(int, Person&);
	void Sleep(float, Person&);
private:
	float sleep_time = 6;
};
#endif //!DAY
