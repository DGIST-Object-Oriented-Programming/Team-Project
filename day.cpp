#include "day.h"


Day::Day() {}
Day::Day(Person& _person) {
	_person.changeSleepEff(0);
}

void Day::Study(Subject& _sub, Person& _person) {
	float TotalEff;
	float sleep_eff;
	int Level;
	
	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	//TotalEff = sleep_eff + _sub.TemEff(Level, 8, sleep_eff);
	TotalEff = sleep_eff + _sub.TemEff(Level, 8, sleep_time);

	//성취도 변화에 따른 레벨 증가
	int postLevel;
	postLevel = int(_person.gettotal_achive() / 2.5);
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(8);//공부시간 상승
	_sub.SetAchievement(8 * TotalEff);//성취도 상승

} 

//한과목만 공부, 8시간
void Day::Study(float _time, Subject& _sub, Person& _person) {
	float TotalEff;
	float sleep_eff;
	int Level;

	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	//TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_eff);
	TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_time);

	//성취도 변화에 따른 레벨 증가
	int postLevel;
	postLevel = int(_person.gettotal_achive() / 2.5);
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(_time);//공부시간 상승
	_sub.SetAchievement(_time * TotalEff); //성취도 상승
}

//잠자는 시간 별 공부효율 변화 세팅
void Day::Sleep(Person& _person) {
	sleep_time = 6;
	_person.changeSleepEff(0);
	_person.changeLeftday();
}

void Day::Sleep(int sleepTime, Person& _person) {
	_person.changeLeftday();
	sleep_time = sleepTime;
	if (sleepTime < 6) {
		_person.changeSleepEff(-0.05f);
	}
	else if (sleepTime >= 6 && sleepTime < 10) {
		_person.changeSleepEff(0);
	}
	else {
		_person.changeSleepEff(0.05f);
	}
}
