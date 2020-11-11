#pragma once
#include<iostream>
#include "subject.h"

#ifndef DAY
class Day : public Subject, Person{
protected:
	int leftday;
	float effSleep;
public:
	Day(int);
	void Study(Subject&, Person&); //�Ѱ��� ����, 8�ð�
	void Study(int, Subject&, Person&);
	void Study(float, Subject&, Person&);

	void Sleep();
	void Sleep(int);
	void Sleep(float);
};
#endif //!DAY
