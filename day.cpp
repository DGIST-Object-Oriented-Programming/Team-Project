#include<iostream>
#include "day.h"
#include "subject.h"
#include "person.h"
Day::Day() {}
Day::Day(int leftday, Person& _person){
	_person.changeSleepEff(0);
}

void Day::Study(Subject& _sub, Person& _person) {
	float TotalEff;
	int sleep_eff;
	int Level;

	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	TotalEff = sleep_eff + _sub.TemEff(Level, 8, sleep_eff);

	//���뵵 ��ȭ�� ���� ���� ����
	int postLevel;
	postLevel = _person.gettotal_achive() / 2.5;
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(8);//���νð� ���
	_sub.SetAchievement(8*TotalEff);//���뵵 ���

} //�Ѱ��� ����, 8�ð�
void Day::Study(int _time, Subject& _sub, Person& _person) {
	float TotalEff;
	int sleep_eff;
	int Level;

	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_eff);

	//���뵵 ��ȭ�� ���� ���� ����
	int postLevel;
	postLevel = _person.gettotal_achive() / 2.5;
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(_time);//���νð� ���
	_sub.SetAchievement(_time * TotalEff);//���뵵 ���
}
void Day::Study(float _time, Subject& _sub, Person& _person) {
	float TotalEff;
	int sleep_eff;
	int Level;

	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_eff);

	//���뵵 ��ȭ�� ���� ���� ����
	int postLevel;
	postLevel = _person.gettotal_achive() / 2.5;
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(_time);//���νð� ���
	_sub.SetAchievement(_time * TotalEff);//���뵵 ���
}

//���ڴ� �ð� �� ����ȿ�� ��ȭ ����
void Day::Sleep(Person& _person) {
	_person.changeSleepEff(0);
	_person.changeLeftday();
}
void Day::Sleep(int sleepTime, Person& _person) {
	_person.changeLeftday();
	if (sleepTime < 6) {
		_person.changeSleepEff(-0.05);
	}
	else if (sleepTime >= 10) {
		_person.changeSleepEff(0);
	}
	else {
		_person.changeSleepEff(0.05);
	}
}
void Day::Sleep(float sleepTime, Person& _person) {
	int sleep_eff;
	sleep_eff = _person.getsleep_eff();
	_person.changeLeftday();
	if (sleepTime < 6.0f) {
		_person.changeSleepEff(-0.05);
	}
	else if (sleepTime >= 10.0f) {
		_person.changeSleepEff(0);
	}
	else {
		_person.changeSleepEff(0.05);
	}
}