#pragma once
#include<iostream>
#include "subject.h"

#ifndef DAY
class Day : public Subject {
private:
	int leftday;

public:
	void Study();
	void Study(Subject&); //�Ѱ��� ����, 8�ð�
	void Study(int, Subject&);
	void Study(float, Subject&);

	void Sleep();
	void Sleep(int);
	void Sleep(float);
};
#endif //!DAY
