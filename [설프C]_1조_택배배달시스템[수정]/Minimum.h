#pragma once
#include <iostream>

using namespace std;

class Minimum
{
public:
	Minimum(void);
	~Minimum(void);
	void set_count(int count){_count = count;}; // ���� �Է�
	void set_place(int place){_place = place;}; // ��� ����ؾ� �ϴ� ���
	int get_count(){return _count;}; // ���� ����
	int get_place(){return _place;}; // ��� ����ؾ� �ϴ� ���
private:
	int _count; // ���� ����
	int _place; // ����ؾ� �ϴ� ���
};

