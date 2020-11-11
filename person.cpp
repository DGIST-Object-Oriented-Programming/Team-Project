#include "person.h"

#include <iostream>

void setdaylist() {
	int subject_num;
	std::cout << "How many subjects do u have, today? : "; std::cin >> subject_num; std::cout << std::endl;

	// 과목 저장
	Subject* subjects = new Subject[subject_num];

	std::string subs_name;
	int subs_eff;

	std::cout << "--------------------------------------------------------" << std::endl;
	for (int i = 0; i < subject_num; i++) {
		std::cout << "Enter your Subject name : "; std::cin >> subs_name; std::cout << std::endl;
		std::cout << "Enter your Subject's efficient : "; std::cin >> subs_eff; std::cout << std::endl;

		/* 이거 해줄 함수가 필요
		subjects[i].subject = subs_name;
		subjects[i].eff = subs_eff;
		*/
	}
	std::cout << "--------------------------------------------------------" << std::endl;
}


Person::Person(int a) {
	std::cout << "Enter your name : "; // 이름
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Enter your Student Number : "; // 학번
	std::cin >> personID;
	std::cout << std::endl;
	std::cout << "Enter your sleep efficient : "; std::cin >> sleep_eff; std::cout << std::endl; // 수면효율
	std::cout << "Hello " << name << "!, your current level is " << level << "." << std::endl;

	leftday = a; // 남은 요일

	// 테스트 코드 자동 실행
	while (leftday != 0) {
		setdaylist(); // 과목 리스트를 받음, 과목들이 생성됨
		TodayResult(); // 평가를 진행
		delete[] subjects; // 평가 후 과목 삭제, 다음날 다시 생성
		leftday--;
	}

	// 마지막 날용 결과문 보여주기
	TodayResult();

}



Person::~Person() {

	// 시험이 끝난 후 평가
	int temp;
	std::cout << "Do you want to evaluate your exam result?" << std::endl;
	std::cout << "1. Yes     2. No";	std::cin >> temp;	std::cout << std::endl;
	if (temp == 1) {
		AfterTest();
	}
	else {
		std::cout << "ByeBye " << name << std::endl;
	}

	// 지워줘야할 놈들 지워주기
	delete[] subjects;
	std::cout << "Thank you for using our program. Bye " << name << std::endl;
}

int Person::changeTotalAchive(int _achive) { total_achive += _achive; }//성취도 더해주기

//변수 바꾸기
void Person::changeLevel(int _num) { level = _num; }
void Person::changeLeftday() { leftday = -1; }
void Person::changeSleepEff(int _num) { sleep_eff = _num; }


// 변수 가져오기
int Person::getID() { return personID; }
int Person::getlevel() { return level; }
int Person::getleftday() { return leftday; }
int Person::getsleep_eff() { return sleep_eff; }
std::string Person::getname() { return name; }
int Person::gettotal_achive() { return total_achive; }
