#include "person.h"

#include <iostream>

void Person::setdaylist() {
	std::cout << "How many subjects do u have? : "; std::cin >> subject_num; std::cout << std::endl;

	// 과목 저장
	subjects = new Subject[subject_num];

	std::string subs_name;
	float subs_eff;

	std::cout << "----------------------------------------------------------------------------------" << std::endl;
	std::cout << "please give me Subject's information" << std::endl<<std::endl;
	for (int i = 0; i < subject_num; i++) {
		std::cout << "Enter your Subject name : "; std::cin >> subs_name; std::cout << std::endl;

		std::cout << "Enter your Subject's efficient" <<  " (please put 0 if you can't decide) :  ";
		std::cin >> subs_eff; std::cout << std::endl;

		// eff가 0~1 사이에 없을 경우
		while (subs_eff > 1 || subs_eff < 0) {
			std::cout << "Please entet again. (Eff must be in 0~1) : "; std::cin >> subs_eff; std::cout << std::endl;
		}

		subjects[i].SetSub(subs_name);
		if (subs_eff == 0) {
			subjects[i].SetEff(0.25);
		}
		else {
			subjects[i].SetEff(subs_eff);
		}
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}


Person::Person(int a) {
	std::cout << "Enter your name : "; // 이름
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Enter your Student Number : "; // 학번
	std::cin >> personID;
	std::cout << std::endl;
	std::cout << "Hello " << name << "!, your current level is " << level << "." << std::endl<<std::endl;
	leftday = a; // 남은 요일
	setdaylist(); 
}



Person::~Person() {
	delete[] subjects;
	std::cout << "▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣" << std::endl;
	std::cout << "▣                                                                              ▣" << std::endl;
	std::cout << "▣  Thank you for using our program. Bye                                        ▣" << std::endl;
	std::cout << "▣  Good Luck!                                                                  ▣" << std::endl;
	std::cout << "▣                                                                              ▣" << std::endl;
	std::cout << "▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣" << std::endl << std::endl;;

}


// 변수 가져오기
int Person::getID() { return personID; }
int Person::getlevel() { return level; }
int Person::getleftday() { return leftday; }
float Person::getsleep_eff() { return sleep_eff; }
std::string Person::getname() { return name; }
