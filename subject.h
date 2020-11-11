#pragma once

#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif //!IOSTREAM

#ifndef STRING
#define STRING
#include<string>
#endif //!ISTRING

#ifndef SUBJECT
#define SUBJECT

class Subject {
private:
	float eff;
	float Achievement; //성취도
	float TotalStudy; //공부시간
					 //혹시 나중에 다르게 쓰일까 싶어서 성취도와 공부시간을 분리해둠. 
					 //성취도는 공부를 안하면 내려갈 수 있고, 학습의 효율이 계속 달라지기 때문에 공부시간과 성취도를 비교하면 공부 효율도 알 수 있다.
	std::string subject;
protected:
	Subject();
	Subject(std::string); //과목명만 받는 경우, 효율은 0.25로 초기화
	Subject(std::string, float); //과목명과 효율을 직접 입력받는 경우
	virtual  ~Subject();

	float GetEff() { return eff; } //효율에 접근하기 위해서 쓰는 함수
	void SetEff(float _eff); //효율을 임의의 값으로 설정
	float TemEff(int _level, float _Study, float _Sleep); // 레벨,  공부시간, 수면시간을 입력받아서 효율을 계산해서 리턴해줌. Subject의 효율은 변하지 않음. 

	void SetSub(std::string); // 과목명 변경 함수
	std::string GetSubName() { return subject; }

	float GetStudyTime() { return TotalStudy; }; // 공부시간 접근 함수
	void SetStudyTime(float); // 공부시간 설정 함수, 입력값 만큼 TotalStudy가 늘어난다.

	float GetAchievement() { return Achievement; }// 성취도 접근 함수
	void SetAchievement(float); // 성취도 설정 함수, 성취도는 경우에 따라 +도, -도 될 수 있다.

	void StudyEffJudge(); //공부시간 대비 성취도를 판단해서 공부를 얼마나 효율적으로 했는 지 알 수 있습니다.
						  //코드 짜다보니 있으면 좋을 것 같아서 추가해봤습니다!
};
#endif // !SUBJECT
