#pragma once
#include<iostream>

#ifndef SUBJECT

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
#endif // !SUBJECT