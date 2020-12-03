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
	float Achievement; //���뵵
	float TotalStudy; //���νð�
					 //Ȥ�� ���߿� �ٸ��� ���ϱ� �; ���뵵�� ���νð��� �и��ص�. 
					 //���뵵�� ���θ� ���ϸ� ������ �� �ְ�, �н��� ȿ���� ��� �޶����� ������ ���νð��� ���뵵�� ���ϸ� ���� ȿ���� �� �� �ִ�.
	std::string subject;
public:
	Subject();
	Subject(std::string); //����� �޴� ���, ȿ���� 0.25�� �ʱ�ȭ
	Subject(std::string, float); //������ ȿ���� ���� �Է¹޴� ���
	virtual  ~Subject();

	float GetEff() { return eff; } //ȿ���� �����ϱ� ���ؼ� ���� �Լ�
	void SetEff(float _eff); //ȿ���� ������ ������ ����
	float TemEff(int _level, float _Study, float _Sleep); // ����,  ���νð�, ����ð��� �Է¹޾Ƽ� ȿ���� ����ؼ� ��������. Subject�� ȿ���� ������ ����. 

	void SetSub(std::string); // ����� ���� �Լ�
	std::string GetSubName() { return subject; }

	float GetStudyTime() { return TotalStudy; }; // ���νð� ���� �Լ�
	void SetStudyTime(float); // ���νð� ���� �Լ�, �Է°� ��ŭ TotalStudy�� �þ��.

	float GetAchievement() { return Achievement; }// ���뵵 ���� �Լ�
	void SetAchievement(float); // ���뵵 ���� �Լ�, ���뵵�� ��쿡 ���� +��, -�� �� �� �ִ�.

	void StudyEffJudge(); //���νð� ��� ���뵵�� �Ǵ��ؼ� ���θ� �󸶳� ȿ�������� �ߴ� �� �� �� �ֽ��ϴ�.
						  //�ڵ� ¥�ٺ��� ������ ���� �� ���Ƽ� �߰��غý��ϴ�!
};
#endif // !SUBJECT