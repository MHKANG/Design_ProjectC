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
void SPAlgorithm::init_car(int N, int place)
{
	car = new Deliver(N, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0, place); // 맨처음 택배차 초기화
}
void SPAlgorithm::SA_run()
{
	bool check = false;
	bool check2 = false;
	int count = 0;
	int N;
	int place = 0; // 현재 택배차의 위치를 알리는 변수
	cout << "SmallPriority 알고리즘을 수행합니다." <<endl;
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
		for(int i = 0; i < 10 ; i++)
		{
			for(int j = 0; j < 10; j ++)
			{
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
			} // 내리는 것 종료
			check2 = false;// check2 값 초기화 (안해주면 while문에 접근을 하지 못해 f_Minimum 함수의 i 값이 변하지 않음)
			while(!check2) // 택배차 용량 싣는 경우
			{
				if(car->Get_max() >= f_Minimum(i)) // 최소 배달 수가 현재 용량 보다 작다면
				{
					if(min.get_place() == 0 && place == i) // 최소 배달 수를 가진 장소가 A라면
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
					if(car->Get_max() == 0|| f_Minimum(i) == 100) // 차가 꽉 찼을 경우
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
			place = place +1; // 다음 장소로 차 이동*/
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
			reset_ary(); // 종료 후 배열 재전개
			reset_min(); // min_check 배열 초기화
			print_cycle();
			record[record_count][0] = N;
			record[record_count][1] = cycle_count;
			record_count++;
			cycle_count = 0; // 순환 횟수 초기화
			check = true;
		}
	}
}
void SPAlgorithm::print_record()
{
	cout << " SP알고리즘 결과 값" <<endl;
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
			if(record[i][1] > 10)
			{
				cout << setw(19) <<"│입력 받은 N 값 : " << record[i][0] << " " << "순환 횟수 : " << record[i][1] <<"  │" <<endl;
			}
			else
			{
				cout << setw(19) <<"│입력 받은 N 값 : " << record[i][0] << " " << "순환 횟수 : " << record[i][1] <<"   │" <<endl;
			}
		}
		cout << "└──────────────────┘"<<endl;
	}
}
int SPAlgorithm::f_Minimum(int _place) // place는 장소 변수
{
	if(end_line(_place) == true)
	{
		min.set_count(0);
		min.set_place(0);
		return 100;
	}
	else
	{
		Minimum temp; // 임시 저장 객체
		int count = 0; // 비교 카운트
		int start = 0;
		temp.set_count(D_ary[_place][start]); // 맨처음 d_ary의 [0][0]을 대입
		temp.set_place(start); // 0시작지점 입력
		if(temp.get_count() == 0) // 입력 지정 값이 0이라면
		{
			while(1) // 입력 받은 값의 배달물 크기가 0이 아닐 때까지 반복
			{
				min_check[_place][start] = true; // 배달물이 0인 지점의 불타입을 변경
				start = start+1; // 다음 장소로 이동
				temp.set_count(D_ary[_place][start]); // 다음 장소의 정보 입력
				temp.set_place(start);
				if(temp.get_count() != 0)
				{
					break;
				}
			
			}
		}
		start = 0; // 초기화
		for(int k = 0; k <10; k++)
		{
			if(D_ary[_place][k] < temp.get_count() && min_check[_place][k] == false) // 비교해서 작을 경우
			{
				min.set_count(D_ary[_place][k]);
				min.set_place(k);
				if(min.get_count() == 0) // 미니멈 값이 0이라면
				{
					min.set_count(temp.get_count()); // 0이 아닌 비교 대상으로 미니멈으로 변경
					min.set_place(temp.get_place());
					min_check[_place][k] = true;
				}
				temp.set_count(min.get_count()); //현재 자기 자신 값 저장(다음 비교시 사용 가능)
				temp.set_place(min.get_place());
			}
			else if(D_ary[_place][k] == temp.get_count() && min_check[_place][k] == false) // 비교해서 같을 경우이면서 자기 자신이 아닐 경우
			{
				min.set_count(temp.get_count()); // 먼저 것에 우선권을 줌
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
	load_list(); // 다시 리스트를 불러옴
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
	check = true; // 모든 포문을 다 돌았을 시에
	return check; 
}
bool SPAlgorithm::end_line(int _place)
{
	bool check = false;
	for(int i = 0; i < 10; i ++)
	{
		if(min_check[_place][i] == true)
		{
			// 이미 검사 끝났을 시
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
	cout << "현재 순환 횟수는  : " << cycle_count <<"입니다."<<endl;
}
void SPAlgorithm::print_ary()
{
	cout << "┌───────────────┐"<<endl;
	for(int i = 0; i < 10; i++)
	{
		cout <<"│";
		for(int j = 0; j < 10 ; j++)
		{
			cout << setw(2) <<D_ary[i][j] <<" ";
		}
		cout <<"│"<< endl;
	}
	cout << "└───────────────┘"<<endl;
}
SPAlgorithm::~SPAlgorithm(void)
{
}
