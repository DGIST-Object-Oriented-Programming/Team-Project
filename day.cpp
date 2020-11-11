#include<iostream>
#include "day.h"
#include "subject.h"
#include "person.h"

Day::Day(int leftday) : leftday(leftday){
	effSleep = 0;
}

void Day::Study(Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = effSleep + _sub.TemEff(_person.level, 8, effSleep);
	_sub.SetStudyTime(8);
	_sub.SetAchievement(8*TotalEff);

} //한과목만 공부, 8시간
void Day::Study(int _time, Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = effSleep + _sub.TemEff(_person.level, _time, effSleep);
	_sub.SetStudyTime(_time);
	_sub.SetAchievement(_time * TotalEff);
}
void Day::Study(float _time, Subject& _sub, Person& _person) {
	float TotalEff;
	TotalEff = effSleep + _sub.TemEff(_person.level, _time, effSleep);
	_sub.SetStudyTime(_time);
	_sub.SetAchievement(_time * TotalEff);
}

void Day::Sleep() {
	effSleep = 0;
	leftday -= 1;
}
void Day::Sleep(int sleepTime) {
	leftday -= 1;
	if (sleepTime < 6) {
		effSleep = -0.05;
	}
	else if (sleepTime >= 10) {
		effSleep = 0.05;
	}
	else {
		effSleep = 0;
	}
}
void Day::Sleep(float sleepTime) {
	leftday -= 1;
	if (sleepTime < 6.0f) {
		effSleep = -0.05;
	}
	else if (sleepTime >= 10.0f) {
		effSleep = 0.05;
	}
	else {
		effSleep = 0;
	}
}