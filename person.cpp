#include "person.h"

#include <iostream>


void Person::setdaylist() {
	std::cout << "How many subjects do u have? : "; 
	std::cin >> subject_num; std::cout << std::endl;

	// 과목 저장
	subjects = new Subject[subject_num];

	std::string subs_name;
	float subs_eff;

	std::cout << "----------------------------------------------------------------------------------" << std::endl << std::endl;
	std::cout << "please give me Subject's information" << std::endl<<std::endl;
	for (int i = 0; i < subject_num; i++) {
		std::cout << "Enter your Subject name : "; std::cin>>subs_name; std::cout << std::endl;

		while (true) {
			try {
				std::cout << "Enter your Subject's efficient (please put 0 if you can't decide) :  ";
				std::cin >> subs_eff;
				if (std::cin.fail() || subs_eff > 1 || subs_eff < 0) throw subs_eff;
				break;
			}
			catch (float f) {
				std::cout << "(ERROR please entet again. Eff must be in 0~1)" << std::endl << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
		}
		std::cout << std::endl;
		subjects[i].SetSub(subs_name);
		if (subs_eff == 0) { subjects[i].SetEff(0.25); }
		else { subjects[i].SetEff(subs_eff); }
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}


Person::Person(int a) {
	while (true) {

		try {
			std::cout << "Enter your name : ";
			std::cin>> name;
			if (std::cin.fail()) throw name;
			break;
		}
		catch (std::string str) {
			std::cout << "(ERROR please enter again. It should be string)" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	}
	std::cout << std::endl;
	while (true) {
		try {
			std::cout << "Enter your Student Number : "; // 학번
			std::cin >> personID;
			if (std::cin.fail() || personID < 0) throw personID;
			break;
		}
		catch (int i) {
			std::cout << "(ERROR please enter again. It should be number)" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	}
	std::cout << std::endl;
	std::cout << "Hello " << name << "!, your current level is " << level << "." << std::endl << std::endl;
	leftday = a; // 남은 요일
	setdaylist(); 
}


Person& Person::instance(int a) {
	static Person* instance = new Person(a);
	return *instance;
}


Person::~Person() {
	delete[] subjects;
}



