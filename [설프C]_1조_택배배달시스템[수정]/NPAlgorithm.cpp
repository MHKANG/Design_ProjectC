#include "NPAlgorithm.h"


NPAlgorithm::NPAlgorithm(void)
{
	cycle_count = 0;
	list_p = 0;
	record_count = 0;
	load_list();
	set_finish();
}
void NPAlgorithm::load_list()
{
	int toa, tob, toc, tod, toe, tof, tog, toh, toi, toj;
	ifstream fin;
	fin.open("DeliveryList.txt");
	if(fin.fail())
	{
		cout << "������ �� �� �����ϴ�." << endl;
	}
	else
	{
		while(!fin.eof())
		{
			fin >>toa >> tob >> toc >> tod >> toe >> tof >> tog >> toh >> toi >> toj;
			D_ary[list_p][0] = toa;
			D_ary[list_p][1] = tob;
			D_ary[list_p][2] = toc;
			D_ary[list_p][3] = tod;
			D_ary[list_p][4] = toe;
			D_ary[list_p][5] = tof;
			D_ary[list_p][6] = tog;
			D_ary[list_p][7] = toh;
			D_ary[list_p][8] = toi;
			D_ary[list_p][9] = toj;
			list_p++;
		}
	}
	list_p = 0; // �� ���� ���� �� �ʱ�ȭ ������
}
void NPAlgorithm::init_car(int N, int place)
{
	car = new Deliver(N, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, place); // ��ó�� �ù��� �ʱ�ȭ
}
void NPAlgorithm::A_run()
{
	bool check = false;
	int N;
	int place = 0; // ���� �ù����� ��ġ�� �˸��� ����
	cout << "NextPriority �˰����� �����մϴ�." <<endl;
	back: // ���ƿ��� �ڸ�
	cout << "�ù����� �뷮�� ������ �ּ���." <<endl;
	cout << "�뷮 : ";
	cin >> N;
	if(N <0)
	{
		cout  << "�߸��� ���� �Է� �ϼ̽��ϴ�. �ٽ� �Է����ּ���." <<endl;
		goto back; // �߸��� �� �Է½� �Է� �ڸ��� ���ư�
	}
	init_car(N, place); // �ù��� �ʱ�ȭ
	cout << "�ʱ� ��� ��Ȳ�� ������ �����ϴ�." <<endl;
	print_ary();
	system("pause");
	while(!check)
	{
		for(int i = 0; i < 10 ; i ++)
		{
			for(int j = 0; j < 10; j ++)
			{
				// �ù������� ��ǰ�� ������ ���
					if(place == i && place == 0 && car->Get_A() > 0)
					{
						car->set_max(car->Get_max() + car->Get_A()); // ��� ����
						car->set_A(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 1 && car->Get_B() > 0)
					{
						car->set_max(car->Get_max() + car->Get_B()); // ��� ����
						car->set_B(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 2 && car->Get_C() > 0)
					{
						car->set_max(car->Get_max() + car->Get_C()); // ��� ����
						car->set_C(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 3 && car->Get_D() > 0)
					{
						car->set_max(car->Get_max() + car->Get_D()); // ��� ����
						car->set_D(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 4 && car->Get_E() > 0)
					{
						car->set_max(car->Get_max() + car->Get_E()); // ��� ����
						car->set_E(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 5 && car->Get_F() > 0)
					{
						car->set_max(car->Get_max() + car->Get_F()); // ��� ����
						car->set_F(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 6 && car->Get_G() > 0)
					{
						car->set_max(car->Get_max() + car->Get_G()); // ��� ����
						car->set_G(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 7 && car->Get_H() > 0)
					{
						car->set_max(car->Get_max() + car->Get_H()); // ��� ����
						car->set_H(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 8 && car->Get_I() > 0)
					{
						car->set_max(car->Get_max() + car->Get_I()); // ��� ����
						car->set_I(0); // ���������� �ִ� ��� ��ǰ 0����
					}
					else if(place == i && place == 9 && car->Get_J() > 0)
					{
						car->set_max(car->Get_max() + car->Get_J()); // ��� ����
						car->set_J(0); // ���������� �ִ� ��� ��ǰ 0����
					}
				//������ �ƴ� ���
				if(car->Get_max() >= D_ary[i][j]) // ���� �뷮�� ����ϰ����ϴ� ��ǰ�� �纸�� Ŭ ���
				{
					if(j == 0 && place == i) // ���� �ù����� A�� ���� �Ǵ� ��ǰ�� ���� ���
					{
						car->set_A(car->Get_A()+D_ary[i][j]); // ���� ���� �Ǿ� �ִ� ���� �߰� ��
						car->set_max(car->Get_max() - D_ary[i][j]); // ���� ���� �� �ִ� �뷮�� ���� ��Ŵ
						D_ary[i][j] = 0; // ��� �Ǿ������� 0���� �ʱ�ȭ
					}
					else if(j == 1 && place == i)
					{
						car->set_B(car->Get_B()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 2 && place == i)
					{
						car->set_C(car->Get_C()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 3 && place == i)
					{
						car->set_D(car->Get_D()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 4 && place == i)
					{
						car->set_E(car->Get_E()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 5 && place == i)
					{
						car->set_F(car->Get_F()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 6 && place == i)
					{
						car->set_G(car->Get_G()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 7 && place == i)
					{
						car->set_H(car->Get_H()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 8 && place == i)
					{
						car->set_I(car->Get_I()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					}
					else if(j == 9 && place == i)
					{
						car->set_J(car->Get_J()+D_ary[i][j]);
						car->set_max(car->Get_max() - D_ary[i][j]);
						D_ary[i][j] = 0;
					} // �ù��� �ƴ� ���ǹ�
					if(car->Get_max() == 0) // ���̻� ���� �� ���� ���
					{
						break;
					}
				}
				else if(car->Get_max() < D_ary[i][j])
				{
					if(j == 0 && car->Get_max() > 0 && place == i)
					{
						car->set_A(car->Get_A()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 1 && car->Get_max() > 0 && place == i)
					{
						car->set_B(car->Get_B()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 2 && car->Get_max() > 0 && place == i)
					{
						car->set_C(car->Get_C()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 3 && car->Get_max() > 0 && place == i)
					{
						car->set_D(car->Get_D()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 4 && car->Get_max() > 0 && place == i)
					{
						car->set_E(car->Get_E()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 5 && car->Get_max() > 0 && place == i)
					{
						car->set_F(car->Get_F()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 6 && car->Get_max() > 0 && place == i) 
					{
						car->set_G(car->Get_G()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 7 && car->Get_max() > 0 && place == i)
					{
						car->set_H(car->Get_H()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 8 && car->Get_max() > 0 && place == i)
					{
						car->set_I(car->Get_I()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(j == 9 && car->Get_max() > 0 && place == i)
					{
						car->set_J(car->Get_J()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // �ù��� �뷮 0
					}
					if(car->Get_max() == 0)
					{
						break;
					}
				}
			}
			place = place +1;
		}
		if(place == 10) // ��ȯ
		{
			place = 0;
			cycle_count = cycle_count+1;
		}
		if(cycle_count%5 == 0)
		{
			cout << "���� ��� ��Ȳ�� ������ �����ϴ�." <<endl;
			print_ary();
			print_cycle();
			system("pause");
		}
		if(end_A() == true )
		{
			cout << "���� ��� ��Ȳ�� ������ �����ϴ�." <<endl;
			print_ary();
			cout << "�˰����� �����մϴ�." <<endl;
			print_cycle();
			reset_ary(); // ������ �迭 ��ü ������
			record[record_count][0] = N;
			record[record_count][1] = cycle_count;
			record_count++;
			cycle_count = 0; // ����Ŭ �ʱ�ȭ
			check = true;
		}
	}
}
void NPAlgorithm::print_record()
{
	cout << " NP�˰��� ��� ��" <<endl;
	cout << "����������������������������������������"<<endl;
	if(record_count == 0)
	{
		cout << "���Է� ���� �����ϴ�.                 ��" <<endl;
		cout << "����������������������������������������"<<endl;

	}
	else
	{
		for(int i = 0; i < record_count; i ++)
		{
			cout << setw(19) <<"���Է� ���� N �� : " << record[i][0] << " " << "��ȯ Ƚ�� : " << record[i][1]<<"  ��" <<endl;
		}
		cout << "����������������������������������������"<<endl;
	}
}
void NPAlgorithm::reset_ary()
{
	load_list(); // �ٽ� ����Ʈ�� �ҷ���
}
void NPAlgorithm::set_finish()
{
	for(int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 10; j++)
		{
			finish[i][j] = false;
		}
	}
}
bool NPAlgorithm::end_A()
{
	bool check = false;
	for(int i = 0; i < 10 ; i ++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(D_ary[i][j] == 0)
			{
				finish[i][j] == true;
			}
			else
			{
				return check;
			}
		}
	}
	check = true; // ��� ������ �� ������ �ÿ�
	return check; 
}
void NPAlgorithm::print_cycle()
{
	cout << "���� ��ȯ Ƚ����  : " << cycle_count <<"�Դϴ�."<<endl;
}
void NPAlgorithm::print_ary()
{
	cout << "����������������������������������"<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout <<"��";
		for(int j = 0; j < 10 ; j++)
		{
			cout << setw(2) << D_ary[i][j] <<" " ;
		}
		cout <<"��"<< endl;
	}
	cout << "����������������������������������"<<endl;
}
NPAlgorithm::~NPAlgorithm(void)
{
}
