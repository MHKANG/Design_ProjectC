#include "DeliverSystem.h"


DeliverSystem::DeliverSystem(void)
{
}
void DeliverSystem::Run()
{
	bool check = false;
	int select_menu;
	while(!check)
	{ 
		system("cls");
		cout <<"┌───────┐"<<endl;
		cout <<"│택배배달시스템│" <<endl;
		cout << "┌──────────────────┐"<<endl;
		cout << "│택배 배달 알고리즘                  │" <<endl;
		cout << "│메뉴를 선택해 주세요.               │" <<endl;
		cout << "│1. NextPriortiy Algorithm           │" << endl;
		cout << "│2. SmallPriortiy Algorithm          │" << endl;
		cout << "│3. 기록 열람                        │" <<endl;
		cout << "│4. 시스템 종료                      │ "<< endl;
		cout << "└──────────────────┘"<<endl;
		cout << "메뉴 선택 : ";
		cin >> select_menu;
		switch(select_menu)
		{
			case 1:
			{
				system("cls");
				NP.A_run();
				system("pause");
				break;
			}
			case 2:
			{
				system("cls");
				SP.SA_run();
				system("pause");
				break;
			}
			case 3:
			{
				system("cls");
				cout << "알고리즘 기록 열람 " <<endl;
				NP.print_record();
				SP.print_record();
				system("pause");
				break;
			}
			case 4:
			{
				cout << "시스템을 종료합니다."<<endl;
				check = true;
				break;
			}
			default:
			{
				cout <<"잘못된 값을 입력하셨습니다." <<endl;
				system("pause");
				break;
			}
		}
	}
}

DeliverSystem::~DeliverSystem(void)
{
}
