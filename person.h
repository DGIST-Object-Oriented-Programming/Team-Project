#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON

class Person {
private:
	std::string name; // ������ �̸�
	int personID;  // ������ �й�
	int level = 0;  // �������� ����
	int leftday = 0; // ���� ����
	float sleep_eff = 0; // �������� ����ȿ��?
	float total_achive;//�� ���뵵 �� ����

public:
	Person(int); //���ڷ� ���� int������ day�� leftday �ʱ�ȭ
	virtual ~Person();
	void changeLevel(int a) { level = level + a; };
	void changeLeftday() { leftday = leftday - 1; }
	void changeSleepEff(float a) { sleep_eff = a; };

	// �׳� get+ ���ϴ°�
	int getID();
	int getlevel();
	int getleftday();
	float getsleep_eff();
	float gettotal_achive() { return total_achive; }

	void setdaylist();
	void changeTotalAchive(int a) { total_achive = total_achive + a; }//�� ���뵵 �� ����
	std::string getname();

	Subject* subjects;
	int subject_num;
};

#endif // !PERSON