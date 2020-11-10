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
	void TemEff(); // 효율을 설정
	void Delsub(); // 과목 삭제나 변경

};
#endif // !SUBJECT