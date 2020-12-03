/////////////////////////////////////////////////////////////////
//�ð����� �κп� ���� �Ű��߰ڳ׿�
//AfterTest�� ��� �κ� ���� �ӽ÷� ����� ���̸�, ������������ �� ������ �����ϴ°� ���� ��
/////////////////////////////////////////////////////////////////

#include "test.h"

void Test::TodayResult(Subject& _sub, Person& _person) {
	int leftday = _person.getleftday(); //���� ��¥
	int dayNum = leftday; //���� ���ۺ��� �������� ī��Ʈ, ���� 14���ε� ù���� D-1�̰� ������ ���� D-14�� 15-_person.leftday
	float achievement = _sub.GetAchievement(); //���뵵
	std::string name = _sub.GetSubName(); //�����
	if (dayNum == 0) { //�⸻��� ������ ��
		std::string ExpGrad; //���� ����
		float ExpScore = 10 * achievement; //���� ����, �Ʒ� ���ǹ����� ���� �������� ��ȯ, ���� ���� 100*_sub.GetAchievement()/10
		if (ExpScore >= 97) { ExpGrad = "A+"; }
		else if (97 > ExpScore && ExpScore >= 94) { ExpGrad = "A0"; }
		else if (94 > ExpScore && ExpScore >= 90) { ExpGrad = "A-"; }
		else if (90 > ExpScore && ExpScore >= 87) { ExpGrad = "B+"; }
		else if (87 > ExpScore && ExpScore >= 84) { ExpGrad = "B0"; }
		else if (84 > ExpScore && ExpScore >= 80) { ExpGrad = "B-"; }
		else if (80 > ExpScore && ExpScore >= 77) { ExpGrad = "C+"; }
		else if (77 > ExpScore && ExpScore >= 74) { ExpGrad = "C0"; }
		else if (74 > ExpScore && ExpScore >= 70) { ExpGrad = "C-"; }
		else if (70 > ExpScore && ExpScore >= 67) { ExpGrad = "D+"; }
		else if (67 > ExpScore && ExpScore >= 64) { ExpGrad = "D0"; }
		else if (64 > ExpScore && ExpScore >= 60) { ExpGrad = "D-"; }
		else { ExpGrad = "F"; }

		std::cout << "D-" << dayNum << ". ������ �⸻����Դϴ�!" << std::endl; //��¥ ���
		std::cout << "����� ���� Level�� " << _person.getlevel() << "�Դϴ�." << std::endl; //���� ���
		std::cout << name << " ���񿡼� ����� ���뵵�� " << achievement << "�Դϴ�." << std::endl; //���뵵 ���
		std::cout << name << " ������ ����Ǵ� ������ " << ExpGrad << "�Դϴ�." << std::endl; // ���� ���� ���
	}
	else {
		std::cout << "D-" << dayNum << std::endl; //��¥ ���
		std::cout << "����� ���� Level�� " << _person.getlevel() << "�Դϴ�." << std::endl; //���� ���
		std::cout << name << " ���񿡼� ����� ���뵵�� " << achievement << "�Դϴ�." << std::endl; //���뵵 ���
	}
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}


void Test::AfterTest(Subject& _sub, int score) {
	float achievement = _sub.GetAchievement(); //���뵵
	std::string name = _sub.GetSubName(); //�����
	float ExpScore = 10 * achievement; // ���뵵 ��� ���� ����
	if (score < ExpScore && (ExpScore - score) / score > 0.3) { //���뵵 > ���� ���� && ������ ���� �̻��� ��(���Ƿ� 30%�� ����) =>������ ������
		std::cout << "���� �Է����ֽ� ȿ���� ���� ���뵵 " << ExpScore << "�� ���� �ܿ� " << score << "��ŭ�� ������ �����̱���." << std::endl;
		std::cout << name << " ���� ���� ����� ��� �����θ� �������ϰ� �ֱ���!" << std::endl;
		std::cout << "������ ������ ���ݰ�, ���� �������� ��ǥ�� ��ƺ�����!" << std::endl;
	}
	else if (score > ExpScore && (score - ExpScore) / score > 0.3) { //���뵵 < ���� ���� && ������ ���� �̻��� ��(���Ƿ� 30%�� ����) =>������ ������
		std::cout << "���� �Է����ֽ� ȿ���� ���� ���뵵 " << ExpScore << "�� ���� ���� " << score << "��ŭ�̳� ������ �����̱���." << std::endl;
		std::cout << name << " ���� ���� ����� ��� �����θ� �������ϰ� �ֱ���!" << std::endl;
		std::cout << "�ڽŰ��� ����, ���� ���� ��ǥ�� ��ƺ�����!" << std::endl;
	}
	else //�� �����θ� �˶� ��õ ���� ���
		std::cout << "���� �Է����ֽ� ȿ���� ���� ���뵵 " << ExpScore << "�� ����� " << score << "�� ������ �����̱���." << std::endl;
	std::cout << name << " ���� ���� ���뵵�� �´� ������ �����̱���!" << std::endl;
	std::cout << "�������� �ɷ��� �� �ƴ� �� ���� ���� �����ϴ�! �� �ڼ��� �����ϰ� ������ ����ϼ���!" << std::endl;
	std::cout << "----------------------------------------------------------------------------------" << std::endl;
}