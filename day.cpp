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

	//���뵵 ��ȭ�� ���� ���� ����
	int postLevel;
	postLevel = int(_person.gettotal_achive() / 2.5);
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(8);//���νð� ���
	_sub.SetAchievement(8 * TotalEff);//���뵵 ���

} 

//�Ѱ��� ����, 8�ð�
void Day::Study(float _time, Subject& _sub, Person& _person) {
	float TotalEff;
	float sleep_eff;
	int Level;

	sleep_eff = _person.getsleep_eff();
	Level = _person.getlevel();
	//TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_eff);
	TotalEff = sleep_eff + _sub.TemEff(Level, _time, sleep_time);

	//���뵵 ��ȭ�� ���� ���� ����
	int postLevel;
	postLevel = int(_person.gettotal_achive() / 2.5);
	_person.changeLevel(postLevel);

	_sub.SetStudyTime(_time);//���νð� ���
	_sub.SetAchievement(_time * TotalEff); //���뵵 ���
}

//���ڴ� �ð� �� ����ȿ�� ��ȭ ����
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
