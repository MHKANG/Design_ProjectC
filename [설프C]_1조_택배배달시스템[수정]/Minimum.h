#pragma once
#include <iostream>

using namespace std;

class Minimum
{
public:
	Minimum(void);
	~Minimum(void);
	void set_count(int count){_count = count;}; // 수량 입력
	void set_place(int place){_place = place;}; // 어디에 배달해야 하는 장소
	int get_count(){return _count;}; // 수량 리턴
	int get_place(){return _place;}; // 어디에 배달해야 하는 장소
private:
	int _count; // 물건 수량
	int _place; // 배달해야 하는 장소
};

