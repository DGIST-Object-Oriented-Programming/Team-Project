#include<iostream>
#include "day.h"
#include "subject.h"
#include "person.h"
Day::Day() {}
Day::Day(int leftday, Person& _person){
	_person.effSleep = 0;
}

void Day::Study(Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = _person.effSleep + _sub.TemEff(_person.level, 8, _person.effSleep);
	_sub.SetStudyTime(8);
	_sub.SetAchievement(8*TotalEff);

} //한과목만 공부, 8시간
void Day::Study(int _time, Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = _person.effSleep + _sub.TemEff(_person.level, _time, _person.effSleep);
	_sub.SetStudyTime(_time);
	_sub.SetAchievement(_time * TotalEff);
}
void Day::Study(float _time, Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = _person.effSleep + _sub.TemEff(_person.level, _time, _person.effSleep);
	_sub.SetStudyTime(_time);
	_sub.SetAchievement(_time * TotalEff);
}

void Day::Sleep(Person& _person) {
	_person.effSleep = 0;
	_person.leftday -= 1;
}
void Day::Sleep(int sleepTime, Person& _person) {
	_person.leftday -= 1;
	if (sleepTime < 6) {
		_person.effSleep = -0.05;
	}
	else if (sleepTime >= 10) {
		_person.effSleep = 0.05;
	}
	else {
		_person.effSleep = 0;
	}
}
void Day::Sleep(float sleepTime, Person& _person) {
	_person.leftday -= 1;
	if (sleepTime < 6.0f) {
		_person.effSleep = -0.05;
	}
	else if (sleepTime >= 10.0f) {
		_person.effSleep = 0.05;
	}
	else {
		_person.effSleep = 0;
	}
}