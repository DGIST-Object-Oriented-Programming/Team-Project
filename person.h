#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON
#define PERSON
class PersonalID {
protected:
	std::string name = ""; // 참여자 이름
	int personID = 0;  // 참여자 학번
	int level = 0;  // 참여자의 레벨
	int leftday = 0; // 남은 요일
	float sleep_eff = 0; // 참여자의 수면효율?
	float total_achive = 0;//총 성취도 합 저장
public:	
	PersonalID() {};
	virtual ~PersonalID() {};
	virtual int getID() = 0;
	virtual int getlevel() = 0;
	virtual int getleftday() = 0;
	virtual float getsleep_eff() = 0;
	virtual std::string getname() = 0;
	virtual float gettotal_achive() = 0;
};

class Person final : public PersonalID {
private:
	//singleton model, person은 단 한번 불리기 때문.
	Person(int);

public:
	static Person& instance(int);
	
	virtual ~Person();
	void changeLevel(int a) { level = level + a; };
	void changeLeftday() { leftday = leftday - 1; }
	void changeSleepEff(float a) { sleep_eff = a; };

	void setdaylist();
	void changeTotalAchive(int a) { total_achive = total_achive + a; }//총 성취도 값 변경

	int getID() override { return personID; }
	int getlevel() override { return level; }
	int getleftday() override { return leftday; }
	float getsleep_eff() override { return sleep_eff; }
	std::string getname() override { return name; }
	float gettotal_achive() override { return total_achive; }

	Subject* subjects;
	int subject_num;
};
#endif // !PERSON
