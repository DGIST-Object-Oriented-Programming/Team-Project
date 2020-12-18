#include <iostream>

#include "person.h"
#include "subject.h"

void letsstart() {
	Test test;
	int a = 0;

	std::cout << "ΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓ" << std::endl;
	std::cout << "ΆΓ                                                                              ΆΓ" << std::endl;
	std::cout << "ΆΓ  Hello. I'm personal Study Planner. I'll help you with your study.           ΆΓ" << std::endl;
	std::cout << "ΆΓ  Good Luck!                                                                  ΆΓ" << std::endl;
	std::cout << "ΆΓ                                                                              ΆΓ" << std::endl;
	std::cout << "ΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓΆΓ" << std::endl << std::endl;;

	// get the leftday 
	std::cout << "How many days are left?  ";
	std::cin >> a;
	std::cout << std::endl;
	while (a <= 0) {
		std::cout << "please enter again (It should be more than 0 days) : ";
		std::cin >> a;
		std::cout << std::endl;
	}

	// make planner
	Person tester = Person::instance(a);

	// repeat task of day
	while (tester.getleftday() > 0) {
		Day day(tester);
		int sub_many;
		std::cout << std::endl;
		std::cout << "How many subjects will you study today? ";
		std::cin >> sub_many;
		std::cout << std::endl;

		for (sub_many; sub_many > 0; sub_many--) {
			// choose subject
			std::cout << "Which subject will you study? select your subject number!" << std::endl;

			for (int i = 0; i < tester.subject_num; i++) {
				std::cout << i << "." << tester.subjects[i].GetSubName() << std::endl;
			}
			int sub_num;
			std::cin >> sub_num;
			std::cout << std::endl;
			float study_time;

			// give study information of day  
			do {
				std::cout << "How long will you study " << tester.subjects[sub_num].GetSubName() << "? " << std::endl;;
				std::cout << "(Each subject's maximum study time per day is 8 hours.If you enter 0, Study time will set 8) : ";
				std::cin >> study_time;
				std::cout << std::endl;
			} while (study_time > 8 || study_time < 0);

			if (study_time == 0) {
				day.Study(tester.subjects[sub_num], tester);
			}
			else {
				day.Study(study_time, tester.subjects[sub_num], tester);
			}
		}

		// give sleep hour of day
		int sleep_hour;
		do {
			std::cout << "please enter sleep hour(less than 12h) : ";
			std::cin >> sleep_hour;
			std::cout << std::endl;
		} while (sleep_hour >= 12 || sleep_hour < 0);
		day.Sleep(sleep_hour, tester);

		// do you want to see result of day?
		int tmp;
		std::cout << "----------------------------------------------------------------------------------" << std::endl;
		std::cout << "Its end of the day! Do you want to see result, today? " << std::endl;
		std::cout << "1. yes  2. no " << std::endl;
		std::cin >> tmp;
		std::cout << std::endl;
		if (tmp == 1) {
			for (int i = 0; i < tester.subject_num; i++) {
				test.TodayResult(tester.subjects[i], tester);
			}
		}
	}


	int p;
	std::cout << "Next Day after the exam" << std::endl;
	std::cout << "Do you want to do Aftertest? " << std::endl;
	std::cout << "(please enter 1 if you want to do or 2 if you don't want)" << std::endl;
	std::cin >> p; std::cout << std::endl;

	if (p == 1) {
		// aftertest
		std::cout << "Let's do Aftertest!" << std::endl;
		int score = 0;
		for (int i = 0; i < tester.subject_num; i++) {
			std::cout << "please enter the score of " << tester.subjects[i].GetSubName() << " : ";
			std::cin >> score;
			std::cout << std::endl;
			test.AfterTest(tester.subjects[i], score);
		}
	}
	else {
		std::cout << "Skip the after test." << std::endl;
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}


int main() {
	letsstart();
	return  0;
}