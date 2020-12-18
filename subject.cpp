#include "subject.h"

Subject::Subject() {
	eff = 0.25;
	TotalStudy = 0;
	Achievement = 0;
	subject = std::string("");
}//���� �̸��� �����ڷ� ���� �ʴ� ���� ����

Subject::Subject(std::string Sub) {//���� �̸��� �����ڷ� �޴� ���
	subject = Sub;
	eff = 0.25;
	TotalStudy = 0;
	Achievement = 0;
}

Subject::Subject(std::string Sub, float _eff) {//���� �̸��� ȿ���� �����ڷ� �޴� ���
	if (_eff <= 1 && _eff >= 0) {
		eff = _eff;
		TotalStudy = 0;
		Achievement = 0;
		subject = Sub;
	}
	else {
		std::cout << "ȿ����  0���� 1������ ���̾�� �մϴ�. " << std::endl;
	}
}

Subject::~Subject() {}//���� new�� �Ҵ��� ������ �����Ƿ� �Ҹ��ڿ� �ʿ��� ���� ����, �ʿ��ϸ� ���� �߰�

void Subject::SetEff(float _eff) {//ȿ���� _eff�� ����
	eff = _eff;
}

//v�� ���� lo, ���� hi�� ���缭 clamp���ִ� �Լ�
float clamp(const float& v, const float& lo, const float& hi) { return (v < lo) ? lo : (hi < v) ? hi : v; }

float Subject::TemEff(int _level, float _Study, int _Sleep) {//����,  ���νð�, ����ð��� �Է¹޾Ƽ� ȿ���� ����ؼ� ��������. Subject�� ȿ���� ������ ����.
	float Eff = eff;
	Eff += clamp(((float)_level / 128) * 0.1f, 0.0f, 0.1f); // level�� ���� ȿ��(0 ~ 128 -> 0 ~ 0.1)
	Eff += clamp((_Study / 8) * 0.05f, 0.0f, 0.05f); // ���νð��� ���� ȿ��(0 ~ 8 -> 0 ~ 0.05)
	Eff += clamp((_Sleep - 6) / 4 * 0.05f, -0.05f, 0.05f); //����ð��� ���� ȿ��(2 ~ 10 -> -0.05 ~ 0.05)
	//Eff += _Sleep;
	return Eff;
}

void Subject::SetSub(std::string Sub) {// ����� ���� �Լ�
	subject = Sub;
}

void Subject::SetStudyTime(float time) {// ���νð� ����(Day Ŭ������ study�Լ��� �� �Լ��� �̿��ؼ� TotalStudy ������ ����)
	TotalStudy += time;
}

void Subject::SetAchievement(float _achievement) {// ���뵵 ���� �Լ�, ���뵵�� ��쿡 ���� +��, -�� �� �� �ִ�.
	Achievement += _achievement;
}

void Subject::StudyEffJudge() {
	if (Achievement < TotalStudy * eff) { //���νð� * �⺻ȿ������ ���뵵�� ������ ��
		std::cout << "�ð� ��� ������ ȿ���� �������ϴ�. ������ ����� ���ϰ� ������ ������ ������!" << std::endl;
	}
	else if (Achievement > TotalStudy * (eff + 0.1)) {//���νð� * �⺻ȿ������ ������� ���� ������ ������ ���
		std::cout << "�ð� ��� ������ �ſ� �����ϴ�. �̴�θ� �����ϸ� A+ !" << std::endl;
	}
	else {//�̿��� ���
		std::cout << "�ð� ��� ������ ȿ���� �������ϴ�. ���ݸ� �� ������ �ϸ� A+ !" << std::endl;
	}
}