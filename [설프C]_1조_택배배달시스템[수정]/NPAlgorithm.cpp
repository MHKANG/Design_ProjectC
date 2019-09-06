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
		cout << "파일을 열 수 없습니다." << endl;
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
	list_p = 0; // 다 집어 넣은 후 초기화 시켜줌
}
void NPAlgorithm::init_car(int N, int place)
{
	car = new Deliver(N, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, place); // 맨처음 택배차 초기화
}
void NPAlgorithm::A_run()
{
	bool check = false;
	int N;
	int place = 0; // 현재 택배차의 위치를 알리는 변수
	cout << "NextPriority 알고리즘을 수행합니다." <<endl;
	back: // 돌아오는 자리
	cout << "택배차의 용량을 설정해 주세요." <<endl;
	cout << "용량 : ";
	cin >> N;
	if(N <0)
	{
		cout  << "잘못된 값을 입력 하셨습니다. 다시 입력해주세요." <<endl;
		goto back; // 잘못된 값 입력시 입력 자리로 돌아감
	}
	init_car(N, place); // 택배차 초기화
	cout << "초기 배달 현황은 다음과 같습니다." <<endl;
	print_ary();
	system("pause");
	while(!check)
	{
		for(int i = 0; i < 10 ; i ++)
		{
			for(int j = 0; j < 10; j ++)
			{
				// 택배차에서 물품을 내리는 경우
					if(place == i && place == 0 && car->Get_A() > 0)
					{
						car->set_max(car->Get_max() + car->Get_A()); // 용랑 증가
						car->set_A(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 1 && car->Get_B() > 0)
					{
						car->set_max(car->Get_max() + car->Get_B()); // 용랑 증가
						car->set_B(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 2 && car->Get_C() > 0)
					{
						car->set_max(car->Get_max() + car->Get_C()); // 용랑 증가
						car->set_C(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 3 && car->Get_D() > 0)
					{
						car->set_max(car->Get_max() + car->Get_D()); // 용랑 증가
						car->set_D(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 4 && car->Get_E() > 0)
					{
						car->set_max(car->Get_max() + car->Get_E()); // 용랑 증가
						car->set_E(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 5 && car->Get_F() > 0)
					{
						car->set_max(car->Get_max() + car->Get_F()); // 용랑 증가
						car->set_F(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 6 && car->Get_G() > 0)
					{
						car->set_max(car->Get_max() + car->Get_G()); // 용랑 증가
						car->set_G(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 7 && car->Get_H() > 0)
					{
						car->set_max(car->Get_max() + car->Get_H()); // 용랑 증가
						car->set_H(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 8 && car->Get_I() > 0)
					{
						car->set_max(car->Get_max() + car->Get_I()); // 용랑 증가
						car->set_I(0); // 차가가지고 있는 배달 물품 0으로
					}
					else if(place == i && place == 9 && car->Get_J() > 0)
					{
						car->set_max(car->Get_max() + car->Get_J()); // 용랑 증가
						car->set_J(0); // 차가가지고 있는 배달 물품 0으로
					}
				//물픔을 싣는 경우
				if(car->Get_max() >= D_ary[i][j]) // 차의 용량이 배달하고자하는 물품의 양보다 클 경우
				{
					if(j == 0 && place == i) // 현재 택배차가 A로 가야 되는 물품을 실을 경우
					{
						car->set_A(car->Get_A()+D_ary[i][j]); // 현재 차에 실어 있는 값에 추가 함
						car->set_max(car->Get_max() - D_ary[i][j]); // 차가 실을 수 있는 용량을 감소 시킴
						D_ary[i][j] = 0; // 모두 실었음으로 0으로 초기화
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
					} // 택배차 싣는 조건문
					if(car->Get_max() == 0) // 더이상 실을 수 없을 경우
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
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 1 && car->Get_max() > 0 && place == i)
					{
						car->set_B(car->Get_B()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 2 && car->Get_max() > 0 && place == i)
					{
						car->set_C(car->Get_C()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 3 && car->Get_max() > 0 && place == i)
					{
						car->set_D(car->Get_D()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 4 && car->Get_max() > 0 && place == i)
					{
						car->set_E(car->Get_E()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 5 && car->Get_max() > 0 && place == i)
					{
						car->set_F(car->Get_F()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 6 && car->Get_max() > 0 && place == i) 
					{
						car->set_G(car->Get_G()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 7 && car->Get_max() > 0 && place == i)
					{
						car->set_H(car->Get_H()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 8 && car->Get_max() > 0 && place == i)
					{
						car->set_I(car->Get_I()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(j == 9 && car->Get_max() > 0 && place == i)
					{
						car->set_J(car->Get_J()+car->Get_max()); 
						D_ary[i][j] = D_ary[i][j] - car->Get_max();
						car->set_max(0); // 택배차 용량 0
					}
					if(car->Get_max() == 0)
					{
						break;
					}
				}
			}
			place = place +1;
		}
		if(place == 10) // 순환
		{
			place = 0;
			cycle_count = cycle_count+1;
		}
		if(cycle_count%5 == 0)
		{
			cout << "현재 배달 현황은 다음과 같습니다." <<endl;
			print_ary();
			print_cycle();
			system("pause");
		}
		if(end_A() == true )
		{
			cout << "최종 배달 현황은 다음과 같습니다." <<endl;
			print_ary();
			cout << "알고리즘을 종료합니다." <<endl;
			print_cycle();
			reset_ary(); // 종료후 배열 전체 재전개
			record[record_count][0] = N;
			record[record_count][1] = cycle_count;
			record_count++;
			cycle_count = 0; // 싸이클 초기화
			check = true;
		}
	}
}
void NPAlgorithm::print_record()
{
	cout << " NP알고리즘 결과 값" <<endl;
	cout << "┌──────────────────┐"<<endl;
	if(record_count == 0)
	{
		cout << "│입력 값이 없습니다.                 │" <<endl;
		cout << "└──────────────────┘"<<endl;

	}
	else
	{
		for(int i = 0; i < record_count; i ++)
		{
			cout << setw(19) <<"│입력 받은 N 값 : " << record[i][0] << " " << "순환 횟수 : " << record[i][1]<<"  │" <<endl;
		}
		cout << "└──────────────────┘"<<endl;
	}
}
void NPAlgorithm::reset_ary()
{
	load_list(); // 다시 리스트를 불러옴
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
	check = true; // 모든 포문을 다 돌았을 시에
	return check; 
}
void NPAlgorithm::print_cycle()
{
	cout << "현재 순환 횟수는  : " << cycle_count <<"입니다."<<endl;
}
void NPAlgorithm::print_ary()
{
	cout << "┌───────────────┐"<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout <<"│";
		for(int j = 0; j < 10 ; j++)
		{
			cout << setw(2) << D_ary[i][j] <<" " ;
		}
		cout <<"│"<< endl;
	}
	cout << "└───────────────┘"<<endl;
}
NPAlgorithm::~NPAlgorithm(void)
{
}
