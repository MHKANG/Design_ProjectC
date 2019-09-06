#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Deliver.h"

using namespace std;

class NPAlgorithm
{
public:
	NPAlgorithm(void);
	~NPAlgorithm(void);
	void load_list(); // 택배 목록 리스트를 불러옴
	void print_ary(); // 현재 배달 현황을 프린트함
	void init_car(int N, int place); // 택배차 초기화
	void print_cycle(); // 순환 횟수 출력
	void A_run(); // 알고리즘 수행
	bool end_A(); // 알고리즘 수행 종료를 알림
	void set_finish(); // finish 값 초기화
	void reset_ary(); // 배열 초기화
	void print_record();

private:
	int D_ary[10][10];
	int record[10][2];
	int record_count;
	Deliver* car; // 택배 수행차
	int cycle_count; // 순환 횟수
	int list_p; // 택배물이 있는 장소
	bool finish[10][10];
};

