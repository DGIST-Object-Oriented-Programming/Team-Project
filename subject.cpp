#include "subject.h"

Subject::Subject() {
	eff = 0.25;
	TotalStudy = 0;
	Achievement = 0;
	subject = std::string("");
}//과목 이름을 생성자로 받지 않는 경우는 없음

Subject::Subject(std::string Sub) {//과목 이름을 생성자로 받는 경우
	subject = Sub;
	eff = 0.25;
	TotalStudy = 0;
	Achievement = 0;
}

Subject::Subject(std::string Sub, float _eff) {//과목 이름과 효율을 생성자로 받는 경우
	if (_eff <= 1 && _eff >= 0) {
		eff = _eff;
		TotalStudy = 0;
		Achievement = 0;
		subject = Sub;
	}
	else {
		std::cout << "효율은  0에서 1사이의 값이어야 합니다. " << std::endl;
	}
}

Subject::~Subject() {}//따로 new로 할당한 공간이 없으므로 소멸자에 필요한 것이 없음, 필요하면 추후 추가

void Subject::SetEff(float _eff) {//효율을 _eff로 변경
	eff = _eff;
}

//v를 하한 lo, 상한 hi에 맞춰서 clamp해주는 함수
float clamp(const float& v, const float& lo, const float& hi) { return (v < lo) ? lo : (hi < v) ? hi : v; }

float Subject::TemEff(int _level, float _Study, float _Sleep) {//레벨,  공부시간, 수면시간을 입력받아서 효율을 계산해서 리턴해줌. Subject의 효율은 변하지 않음.
	float Eff = eff;
	Eff += clamp((_level / 128) * 0.1, 0, 0.1); // level에 따른 효율(0 ~ 128 -> 0 ~ 0.1)
	Eff += clamp((_Study / 8) * 0.05, 0, 0.05); // 공부시간에 따른 효율(0 ~ 8 -> 0 ~ 0.05)
	Eff += clamp((_Sleep - 6) / 4 * 0.05, -0.05, 0.05); //수면시간에 따른 효율(2 ~ 10 -> -0.05 ~ 0.05)
	return Eff;
}

void Subject::SetSub(std::string Sub) {// 과목명 변경 함수
	subject = Sub;
}

void Subject::SetStudyTime(float time) {// 공부시간 설정(Day 클레스의 study함수는 이 함수를 이용해서 TotalStudy 변수에 접근)
	TotalStudy += time;
}

void Subject::SetAchievement(float _achievement) {// 성취도 설정 함수, 성취도는 경우에 따라 +도, -도 될 수 있다.
	Achievement += _achievement;
}

void Subject::StudyEffJudge() {
	if (Achievement < TotalStudy * eff) { //공부시간 * 기본효율보다 성취도가 떨어질 때
		std::cout << "시간 대비 공부의 효율이 안좋습니다. 숙면을 충분히 취하고 열심히 공부해 보세요!" << std::endl;
	}
	else if (Achievement > TotalStudy * (eff + 0.1)) {//공부시간 * 기본효율보다 어느정도 높은 선으로 공부할 경우
		std::cout << "시간 대비 공부의 매우 좋습니다. 이대로만 공부하면 A+ !" << std::endl;
	}
	else {//이외의 경우
		std::cout << "시간 대비 공부의 효율이 괜찮습니다. 조금만 더 열심히 하면 A+ !" << std::endl;
	}
}
