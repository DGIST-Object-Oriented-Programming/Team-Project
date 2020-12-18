#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON
class personalID {
public:
	std::string name; // ������ �̸�
	int personID;  // ������ �й�
	int level = 0;  // �������� ����
	int leftday = 0; // ���� ����
	float sleep_eff = 0; // �������� ����ȿ��?
	float total_achive;//�� ���뵵 �� ����

	virtual int getID() = 0;
	virtual int getlevel() = 0;
	virtual int getleftday() = 0;
	virtual float getsleep_eff() = 0;
	virtual std::string getname() = 0;
	virtual float gettotal_achive() = 0;
};

class Person final : private personalID {
private:
	//singleton model, person�� �� �ѹ� �Ҹ��� ����.
	Person(int);

public:
	static Person& instance(int);
	static Person& instance();

	
	virtual ~Person();
	void changeLevel(int a) { level = level + a; };
	void changeLeftday() { leftday = leftday - 1; }
	void changeSleepEff(float a) { sleep_eff = a; };

	void setdaylist();
	void changeTotalAchive(int a) { total_achive = total_achive + a; }//�� ���뵵 �� ����

	int getID() { return personID; }
	int getlevel() { return level; }
	int getleftday() { return leftday; }
	float getsleep_eff() { return sleep_eff; }
	std::string getname() { return name; }
	float gettotal_achive() { return total_achive; }

	Subject* subjects;
	int subject_num;
};




#endif // !PERSON