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
		cout <<"������������������"<<endl;
		cout <<"���ù��޽ý��ۦ�" <<endl;
		cout << "����������������������������������������"<<endl;
		cout << "���ù� ��� �˰���                  ��" <<endl;
		cout << "���޴��� ������ �ּ���.               ��" <<endl;
		cout << "��1. NextPriortiy Algorithm           ��" << endl;
		cout << "��2. SmallPriortiy Algorithm          ��" << endl;
		cout << "��3. ��� ����                        ��" <<endl;
		cout << "��4. �ý��� ����                      �� "<< endl;
		cout << "����������������������������������������"<<endl;
		cout << "�޴� ���� : ";
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
				cout << "�˰��� ��� ���� " <<endl;
				NP.print_record();
				SP.print_record();
				system("pause");
				break;
			}
			case 4:
			{
				cout << "�ý����� �����մϴ�."<<endl;
				check = true;
				break;
			}
			default:
			{
				cout <<"�߸��� ���� �Է��ϼ̽��ϴ�." <<endl;
				system("pause");
				break;
			}
		}
	}
}

DeliverSystem::~DeliverSystem(void)
{
}
