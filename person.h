#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON

class Person : public  Day, Test {
private:
	std::string name; // 참여자 이름
	int personID;  // 참여자 학번
	int level = 0;  // 참여자의 레벨
	int leftday = 0; // 남은 요일
	int sleep_eff = 0; // 참여자의 수면효율?
public:
	Person(int); //인자로 받은 int값으로 day의 leftday 초기화
	virtual ~Person();

	// 그냥 get+ 원하는거
	int getID();
	int getlevel();
	int getleftday();
	int getsleep_eff();
	std::string getname();

	Subject* subjects;
};

#endif // !PERSON
