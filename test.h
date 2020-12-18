#pragma once
#include<iostream>
#include "subject.h"
#include "person.h"

#ifndef TEST
#define TEST

class Person;

class Test final {
private:
	Test() {};
public:
	static Test& instance() {
		static Test* instance = new Test();
		return *instance;
	}
	virtual ~Test() {};

	void DayNum(Person&);
	void TodayResult(Subject&, Person&);
	void AfterTest(Subject&, int);
};


#endif // !TEST
