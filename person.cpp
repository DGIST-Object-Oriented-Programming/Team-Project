#include "person.h"

#include <iostream>

void setdaylist() {
	int subject_num;
	std::cout << "How many subjects do u have, today? : "; std::cin >> subject_num; std::cout << std::endl;

	// ���� ����
	Subject* subjects = new Subject[subject_num];

	std::string subs_name;
	int subs_eff;

	std::cout << "--------------------------------------------------------" << std::endl;
	for (int i = 0; i < subject_num; i++) {
		std::cout << "Enter your Subject name : "; std::cin >> subs_name; std::cout << std::endl;
		std::cout << "Enter your Subject's efficient : "; std::cin >> subs_eff; std::cout << std::endl;

		/* �̰� ���� �Լ��� �ʿ�
		subjects[i].subject = subs_name;
		subjects[i].eff = subs_eff;
		*/
	}
	std::cout << "--------------------------------------------------------" << std::endl;
}


Person::Person(int a) {
	std::cout << "Enter your name : "; // �̸�
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Enter your Student Number : "; // �й�
	std::cin >> personID;
	std::cout << std::endl;
	std::cout << "Enter your sleep efficient : "; std::cin >> sleep_eff; std::cout << std::endl; // ����ȿ��
	std::cout << "Hello " << name << "!, your current level is " << level << "." << std::endl;

	leftday = a; // ���� ����

	// �׽�Ʈ �ڵ� �ڵ� ����
	while (leftday != 0) {
		setdaylist(); // ���� ����Ʈ�� ����, ������� ������
		TodayResult(); // �򰡸� ����
		delete[] subjects; // �� �� ���� ����, ������ �ٽ� ����
		leftday--;
	}

	// ������ ���� ����� �����ֱ�
	TodayResult();

}



Person::~Person() {

	// ������ ���� �� ��
	int temp;
	std::cout << "Do you want to evaluate your exam result?" << std::endl;
	std::cout << "1. Yes     2. No";	std::cin >> temp;	std::cout << std::endl;
	if (temp == 1) {
		AfterTest();
	}
	else {
		std::cout << "ByeBye " << name << std::endl;
	}

	// ��������� ��� �����ֱ�
	delete[] subjects;
	std::cout << "Thank you for using our program. Bye " << name << std::endl;
}

int Person::changeTotalAchive(int _achive) { total_achive += _achive; }//���뵵 �����ֱ�

//���� �ٲٱ�
void Person::changeLevel(int _num) { level = _num; }
void Person::changeLeftday() { leftday = -1; }
void Person::changeSleepEff(int _num) { sleep_eff = _num; }


// ���� ��������
int Person::getID() { return personID; }
int Person::getlevel() { return level; }
int Person::getleftday() { return leftday; }
int Person::getsleep_eff() { return sleep_eff; }
std::string Person::getname() { return name; }
int Person::gettotal_achive() { return total_achive; }
