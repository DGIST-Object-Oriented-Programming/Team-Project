#pragma once
#include<iostream>
#include "day.h"
#include "test.h"

#ifndef PERSON

class Person : public  Day, Test {
private:
	std::string name; // ������ �̸�
	int personID;  // ������ �й�
	int level = 0;  // �������� ����
	int leftday = 0; // ���� ����
	int sleep_eff = 0; // �������� ����ȿ��?
	float total_achive;//�� ���뵵 �� ����

public:
	Person(int); //���ڷ� ���� int������ day�� leftday �ʱ�ȭ
	virtual ~Person();
	void changeLevel(int);
	void changeLeftday();
	void changeSleepEff(int);

	// �׳� get+ ���ϴ°�
	int getID();
	int getlevel();
	int getleftday();
	int getsleep_eff();
	int gettotal_achive();

	int changeTotalAchive(int);//�� ���뵵 �� ����
	std::string getname();

	Subject* subjects;
};

#endif // !PERSON
