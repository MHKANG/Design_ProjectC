#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Deliver.h"
#include "Minimum.h"

using namespace std;

class SPAlgorithm
{
public:
	SPAlgorithm(void);
	~SPAlgorithm(void);
	void load_list(); // �ù� ��� ����Ʈ�� �ҷ���
	void print_ary(); // ���� ��� ��Ȳ�� ����Ʈ��
	void init_car(int N, int place); // �ù��� �ʱ�ȭ
	void print_cycle(); // ��ȯ Ƚ�� ���
	void SA_run(); // �˰��� ����
	bool end_A(); // �˰��� ���� ���Ḧ �˸�
	bool end_line(int _place); // � ����� ��� ����� �������� �˸�i
	void set_finish(); // finish �� �ʱ�ȭ
	void set_min(); // min ���� 0���� �ƴ��� �Ǵ�
	int f_Minimum(int _place); // ���� ���� ���� ã��
	void print_check();
	void reset_min();
	void reset_ary(); // �迭 �ʱ�ȭ
	void print_record();
private:
	int D_ary[10][10];
	int record[10][2];
	int record_count;
	Minimum min; // �ּҰ� ����
	Deliver* car; // �ù� ������
	int cycle_count; // ��ȯ Ƚ��
	int list_p; // �ù蹰�� �ִ� ���
	bool finish[10][10];
	bool min_check[10][10];

};

