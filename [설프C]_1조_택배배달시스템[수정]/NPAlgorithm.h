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
	void load_list(); // �ù� ��� ����Ʈ�� �ҷ���
	void print_ary(); // ���� ��� ��Ȳ�� ����Ʈ��
	void init_car(int N, int place); // �ù��� �ʱ�ȭ
	void print_cycle(); // ��ȯ Ƚ�� ���
	void A_run(); // �˰��� ����
	bool end_A(); // �˰��� ���� ���Ḧ �˸�
	void set_finish(); // finish �� �ʱ�ȭ
	void reset_ary(); // �迭 �ʱ�ȭ
	void print_record();

private:
	int D_ary[10][10];
	int record[10][2];
	int record_count;
	Deliver* car; // �ù� ������
	int cycle_count; // ��ȯ Ƚ��
	int list_p; // �ù蹰�� �ִ� ���
	bool finish[10][10];
};

