#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON
#define PERSON
class personalID {
protected:
	std::string name = ""; // ������ �̸�
	int personID = 0;  // ������ �й�
	int level = 0;  // �������� ����
	int leftday = 0; // ���� ����
	float sleep_eff = 0; // �������� ����ȿ��?
	float total_achive = 0;//�� ���뵵 �� ����
public:	
	personalID() {};
	virtual ~personalID() {};
	virtual int getID() = 0;
	virtual int getlevel() = 0;
	virtual int getleftday() = 0;
	virtual float getsleep_eff() = 0;
	virtual std::string getname() = 0;
	virtual float gettotal_achive() = 0;
};

class Person final : public personalID {
private:
	//singleton model, person�� �� �ѹ� �Ҹ��� ����.
	Person(int);

public:
	static Person& instance(int);
	
	virtual ~Person();
	void changeLevel(int a) { level = level + a; };
	void changeLeftday() { leftday = leftday - 1; }
	void changeSleepEff(float a) { sleep_eff = a; };

	void setdaylist();
	void changeTotalAchive(int a) { total_achive = total_achive + a; }//�� ���뵵 �� ����

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