#pragma once
#include<iostream>
#include "subject.h"

#ifndef DAY
class Day : public Subject, Person{
public:
	Day();
	Day(int, Person&);
	void Study(Subject&, Person&); //�Ѱ��� ����, 8�ð�
	void Study(int, Subject&, Person&);
	void Study(float, Subject&, Person&);

	void Sleep(Person&);
	void Sleep(int, Person&);
	void Sleep(float, Person&);
};
#endif //!DAY
