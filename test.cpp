/////////////////////////////////////////////////////////////////
//아직 수정중
//성취도 계산식을 잊어버렸고... 각 과목마다 성취도를 출력해야하는데 어... 그리고 레벨은 어디서 받아야하죠
//저 위의 것들부터 다 하고 나서 시각적인 것들에 대해 신경쓰려고요
/////////////////////////////////////////////////////////////////

#include<iostream>
#include "test.h"
#include "day.h"
#include "subject.h"
#include "person.h"

void Test::TodayResult(Subject& _sub, Person& _person) {
	int dayNum = 15 - _person.leftday; //공부 시작부터 몇일인지 카운트, 원래 14일인데 첫날이 D-1이고 마지막 날이 D-14라서 15-leftday
	if (dayNum == 14) { //기말고사 전날일 때
		std::string ExpGrad; //예상 학점
		float ExpScore = 100 * _sub.GetAchievement() / 최대 성취도; //예상 점수, 아래 조건문들을 통해 학점으로 변환
		if ( ExpScore >= 97 )
			ExpGrad = "A+";
		else if ( 97 > ExpScore >= 94 )
			ExpGrad = "A0";
		else if ( 94 > ExpScore >= 90 )
			ExpGrad = "A-";
		else if ( 90 > ExpScore >= 87 )
			ExpGrad = "B+";
		else if ( 87 > ExpScore >= 84 )
			ExpGrad = "B0";
		else if ( 84 > ExpScore >= 80 )
			ExpGrad = "B-";
		else if ( 80 > ExpScore >= 77 )
			ExpGrad = "C+";
		else if ( 77 > ExpScore >= 74 )
			ExpGrad = "C0";
		else if ( 74 > ExpScore >= 70 )
			ExpGrad = "C-";
		else if ( 70 > ExpScore >= 67 )
			ExpGrad = "D+";
		else if ( 67 > ExpScore >= 64 )
			ExpGrad = "D0";
		else if ( 64 > ExpScore >= 60 )
			ExpGrad = "D-";
		else
			ExpGrad = "F";

		std::cout << "D-" << dayNum << ". 내일이 기말고사입니다!" << std::endl; //날짜 출력
		std::cout << "당신의 현재 Level은 " << _person.level << "입니다." << std::endl; //레벨 출력
		std::cout << 과목명 << " 과목에서 당신의 성취도는 " << _sub.GetAchievement() << "입니다." << std::endl; //성취도 출력
		std::cout << 과목명 << " 시험의 예상되는 학점은 " << ExpGrad << "입니다." << std::endl; // 예상 학점 출력
	}
	else {
		std::cout << "D-" << dayNum << std::endl; //날짜 출력
		std::cout << "당신의 현재 Level은 " << _person.level << "입니다." << std::endl; //레벨 출력
		std::cout << 과목명 << " 과목에서 당신의 성취도는 " << GetAchievement() << "입니다." << std::endl; //성취도 출력
	}
}


void Test::AfterTest(Subject& _sub, int score) {
	float ExpScore = 100 * GetAchievement() / 최대 성취도; // 성취도 기반 예상 점수
	if ( score < ExpScore && ( ExpScore - score ) / score > 일정 수치 ) { //성취도 > 시험 점수 && 오차가 일정 이상일 때 =>본인의 과대평가
		std::cout << 과목명 << " 과목에 대해 당신은 당신 스스로를 과대평가하고 있군요! 본인의 수준을 깨닫고, 보다 현실적인 목표를 잡아보세요!" << std::endl;
	}
	else if ( score > ExpScore && ( score - ExpScore ) / score > 일정 수치 ) { //성취도 < 시험 점수 && 오차가 일정 이상일 때 =>본인의 과소평가
		std::cout << 과목명 << " 과목에 대해 당신은 당신 스스로를 과소평가하고 있군요! 자신감을 갖고, 보다 높은 목표를 잡아보세요!" << std::endl;
	}
	else //너 스스로를 알라
		std::cout << 과목명 << " 과목에 대해 성취도에 맞는 점수를 얻으셨군요! 스스로를 아는 것 역시 아주 좋은 자세입니다! 이 자세를 유지하고 열심히 노력하세요!" << std::endl;
}

/////////////////////////////////////////////////////////////////
//아직 수정중
/////////////////////////////////////////////////////////////////
