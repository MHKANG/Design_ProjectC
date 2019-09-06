#include "SPAlgorithm.h"


SPAlgorithm::SPAlgorithm(void)
{
	cycle_count = 0;
	list_p = 0;
	record_count = 0;
	load_list();
	set_finish();
	set_min();
}
void SPAlgorithm::load_list()
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
void SPAlgorithm::init_car(int N, int place)
{
	car = new Deliver(N, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, place); // ��ó�� �ù��� �ʱ�ȭ
}
void SPAlgorithm::SA_run()
{
	bool check = false;
	bool check2 = false;
	int count = 0;
	int N;
	int place = 0; // ���� �ù����� ��ġ�� �˸��� ����
	cout << "SmallPriority �˰����� �����մϴ�." <<endl;
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
		for(int i = 0; i < 10 ; i++)
		{
			for(int j = 0; j < 10; j ++)
			{
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
			} // ������ �� ����
			check2 = false;// check2 �� �ʱ�ȭ (�����ָ� while���� ������ ���� ���� f_Minimum �Լ��� i ���� ������ ����)
			while(!check2) // �ù��� �뷮 �ƴ� ���
			{
				if(car->Get_max() >= f_Minimum(i)) // �ּ� ��� ���� ���� �뷮 ���� �۴ٸ�
				{
					if(min.get_place() == 0 && place == i) // �ּ� ��� ���� ���� ��Ұ� A���
					{
						car->set_A(car->Get_A() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 1 && place == i)
					{
						car->set_B(car->Get_B() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 2 && place == i)
					{	
						car->set_C(car->Get_C() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 3 && place == i)
					{
						car->set_D(car->Get_D() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 4 && place == i)
					{
						
						car->set_E(car->Get_E() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 5 && place == i)
					{
						
						car->set_F(car->Get_F() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 6 && place == i)
					{
						car->set_G(car->Get_G() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 7 && place == i)
					{	
						car->set_H(car->Get_H() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 8 && place == i)
					{
						car->set_I(car->Get_I() + min.get_count());
					
						D_ary[i][min.get_place()] = 0;
					}
					if(min.get_place() == 9 && place == i)
					{	
						car->set_J(car->Get_J() + min.get_count());
						car->set_max(car->Get_max() - min.get_count());
						D_ary[i][min.get_place()] = 0;
					}
					if(car->Get_max() == 0|| f_Minimum(i) == 100) // ���� �� á�� ���
					{
						check2 = true;
						break;
					}
				}
				else if(car->Get_max() < f_Minimum(i))
				{
					if(f_Minimum(i) == 100)
					{
						check2 = true;
						break;
					}
					if(min.get_place() == 0 && car->Get_max() > 0 && place == i)
					{
						car->set_A(car->Get_A() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 1 && car->Get_max() > 0 && place == i)
					{
						car->set_B(car->Get_B() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 2 && car->Get_max() > 0 && place == i)
					{
						car->set_C(car->Get_C() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 3 && car->Get_max() > 0 && place == i)
					{
						car->set_D(car->Get_D() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 4 && car->Get_max() > 0 && place == i)
					{
						car->set_E(car->Get_E() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 5 && car->Get_max() > 0 && place == i)
					{
						car->set_F(car->Get_F() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 6 && car->Get_max() > 0 && place == i)
					{
						car->set_G(car->Get_G() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 7 && car->Get_max() > 0 && place == i)
					{
						car->set_H(car->Get_H() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 8 && car->Get_max() > 0 && place == i)
					{
						car->set_I(car->Get_I() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(min.get_place() == 9 && car->Get_max() > 0 && place == i)
					{
						car->set_J(car->Get_J() + car->Get_max());
						D_ary[i][min.get_place()] = D_ary[i][min.get_place()] - car->Get_max();
						car->set_max(0);
					}
					if(car->Get_max() == 0)
					{
						check2 = true;
						break;
					}
				}
			}
			place = place +1; // ���� ��ҷ� �� �̵�*/
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
			reset_ary(); // ���� �� �迭 ������
			reset_min(); // min_check �迭 �ʱ�ȭ
			print_cycle();
			record[record_count][0] = N;
			record[record_count][1] = cycle_count;
			record_count++;
			cycle_count = 0; // ��ȯ Ƚ�� �ʱ�ȭ
			check = true;
		}
	}
}
void SPAlgorithm::print_record()
{
	cout << " SP�˰��� ��� ��" <<endl;
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
			if(record[i][1] > 10)
			{
				cout << setw(19) <<"���Է� ���� N �� : " << record[i][0] << " " << "��ȯ Ƚ�� : " << record[i][1] <<"  ��" <<endl;
			}
			else
			{
				cout << setw(19) <<"���Է� ���� N �� : " << record[i][0] << " " << "��ȯ Ƚ�� : " << record[i][1] <<"   ��" <<endl;
			}
		}
		cout << "����������������������������������������"<<endl;
	}
}
int SPAlgorithm::f_Minimum(int _place) // place�� ��� ����
{
	if(end_line(_place) == true)
	{
		min.set_count(0);
		min.set_place(0);
		return 100;
	}
	else
	{
		Minimum temp; // �ӽ� ���� ��ü
		int count = 0; // �� ī��Ʈ
		int start = 0;
		temp.set_count(D_ary[_place][start]); // ��ó�� d_ary�� [0][0]�� ����
		temp.set_place(start); // 0�������� �Է�
		if(temp.get_count() == 0) // �Է� ���� ���� 0�̶��
		{
			while(1) // �Է� ���� ���� ��޹� ũ�Ⱑ 0�� �ƴ� ������ �ݺ�
			{
				min_check[_place][start] = true; // ��޹��� 0�� ������ ��Ÿ���� ����
				start = start+1; // ���� ��ҷ� �̵�
				temp.set_count(D_ary[_place][start]); // ���� ����� ���� �Է�
				temp.set_place(start);
				if(temp.get_count() != 0)
				{
					break;
				}
			
			}
		}
		start = 0; // �ʱ�ȭ
		for(int k = 0; k <10; k++)
		{
			if(D_ary[_place][k] < temp.get_count() && min_check[_place][k] == false) // ���ؼ� ���� ���
			{
				min.set_count(D_ary[_place][k]);
				min.set_place(k);
				if(min.get_count() == 0) // �̴ϸ� ���� 0�̶��
				{
					min.set_count(temp.get_count()); // 0�� �ƴ� �� ������� �̴ϸ����� ����
					min.set_place(temp.get_place());
					min_check[_place][k] = true;
				}
				temp.set_count(min.get_count()); //���� �ڱ� �ڽ� �� ����(���� �񱳽� ��� ����)
				temp.set_place(min.get_place());
			}
			else if(D_ary[_place][k] == temp.get_count() && min_check[_place][k] == false) // ���ؼ� ���� ����̸鼭 �ڱ� �ڽ��� �ƴ� ���
			{
				min.set_count(temp.get_count()); // ���� �Ϳ� �켱���� ��
				min.set_place(temp.get_place());
			}
		}
	}
	return min.get_count();
}
void SPAlgorithm::set_min()
{
	for(int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 10; j++)
		{
			min_check[i][j] = false;
		}
	}
}
void SPAlgorithm::reset_ary()
{
	load_list(); // �ٽ� ����Ʈ�� �ҷ���
}
void SPAlgorithm::reset_min()
{
	set_min();
}
void SPAlgorithm::set_finish()
{
	for(int i = 0; i < 10; i ++)
	{
		for(int j = 0; j < 10; j++)
		{
			finish[i][j] = false;
		}
	}
}
bool SPAlgorithm::end_A()
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
bool SPAlgorithm::end_line(int _place)
{
	bool check = false;
	for(int i = 0; i < 10; i ++)
	{
		if(min_check[_place][i] == true)
		{
			// �̹� �˻� ������ ��
		}
		else
		{
			return check;
		}
	}
	check = true;
	return check;
}
void SPAlgorithm::print_check()
{
	for(int i = 0; i <10; i++)
	{
		for(int j = 0; j < 10 ; j++)
		{
			cout << min_check[i][j] << " ";
		}
		cout << endl;
	}
}
void SPAlgorithm::print_cycle()
{
	cout << "���� ��ȯ Ƚ����  : " << cycle_count <<"�Դϴ�."<<endl;
}
void SPAlgorithm::print_ary()
{
	cout << "����������������������������������"<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout <<"��";
		for(int j = 0; j < 10 ; j++)
		{
			cout << setw(2) <<D_ary[i][j] <<" ";
		}
		cout <<"��"<< endl;
	}
	cout << "����������������������������������"<<endl;
}
SPAlgorithm::~SPAlgorithm(void)
{
}
