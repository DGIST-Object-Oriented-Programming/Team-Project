#include<iostream>
#include "test.h"


void Test::TodayResult() {
	int dayNum = 14 - leftday;
	if (dayNum == 14) {
		std::string ExpGrad; //예상 학점
		int ExpScore = 100 * 성취도 / 최대 성취도;
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
		std::cout << "당신의 현재 Level은 " << "--레벨 어디서 받죠--" << "입니다." << std::endl; //레벨 출력
		std::cout << "당신의 성취도는 " << "--성취도 어디서 받죠--" << "입니다." << std::endl; //성취도 출력
		std::cout << "--과목--" << " 시험의 예상되는 학점은 " << ExpGrad << "입니다." << std::endl; // 예상 학점 출력
	}
	else {
		std::cout << "D-" << dayNum << std::endl; //날짜 출력
		std::cout << "당신의 현재 Level은 " << "--레벨 어디서 받죠--" << "입니다." << std::endl; //레벨 출력
		std::cout << "당신의 성취도는 " << "--성취도 어디서 받죠--" << "입니다." << std::endl; //성취도 출력
	}
}


void Test::AfterTest() {
	int ExpScore = 100 * 성취도 / 최대 성취도; // 성취도 기반 예상 점수
	if ( score < ExpScore && ( ExpScore - score ) / score > 일정 수치 ) { //성취도 > 시험 점수 && 오차가 일정 이상일 때 =>본인의 과대평가
		std::cout << Subject << "과목에 대해 당신은 당신 스스로를 과대평가하고 있군요! 본인의 수준을 깨닫고, 보다 현실적인 목표를 잡아보세요!" << std::endl;
	}
	else if ( score > ExpScore && ( score - ExpScore ) / score > 일정 수치 ) { //성취도 < 시험 점수 && 오차가 일정 이상일 때 =>본인의 과소평가
		std::cout << Subject << "과목에 대해 당신은 당신 스스로를 과소평가하고 있군요! 자신감을 갖고, 보다 높은 목표를 잡아보세요!" << std::endl;
	}
	else //너 스스로를 알라
		std::cout << Subject << "과목에 대해 성취도에 맞는 점수를 얻으셨군요! 스스로를 아는 것 역시 아주 좋은 자세입니다! 이 자세를 유지하고 열심히 노력하세요!" << std::endl;
}

/////////////////
//아직 수정중//
////////////////
