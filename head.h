#include <iostream>

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
class Day : public Subject {
private:
	int leftday;

public:
	void Study();
	void Study(Subject&); //한과목만 공부, 8시간
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
	std::string name; // 참여자 이름
	int personID;  // 참여자 학번
	int level = 0;  // 참여자의 레벨
public:
	Person();
	~Person();



}; #pragma once
