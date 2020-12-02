#pragma once
#include<iostream>
#include "subject.h"
#include "person.h"

#ifndef TEST
#define TEST

class Person;

class Test {
public:
	Test() {};
	~Test() {};

	void TodayResult(Subject& _sub, Person& _person);
	void AfterTest(Subject& _sub, int score);
};

#endif // !TEST
