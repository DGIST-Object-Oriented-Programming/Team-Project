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
public:
	Person(int); //���ڷ� ���� int������ day�� leftday �ʱ�ȭ
	~Person();
};

#endif // !PERSON


