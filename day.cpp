#include<iostream>
#include "day.h"

void Study() {}
void Study(Subject&) {} //�Ѱ��� ����, 8�ð�
void Study(int, Subject&) {}
void Study(float, Subject&) {}

void Sleep() {}
void Sleep(int) {}
void Sleep(float) {}