#include <iostream>

class Subject {
private:
	float eff;
	std::string subject;
protected:
	Subject();
	virtual  ~Subject();
	void SetEff();
	void TemEff(); // ȿ���� ����
	void Delsub(); // ���� ������ ����

};
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

class Test {
	void TodayResult();
	void AfterTest();
};


class Person : public  Day, Test {
private:
	std::string name; // ������ �̸�
	int personID;  // ������ �й�
	int level = 0;  // �������� ����
public:
	Person();
	~Person();



}; #pragma once
