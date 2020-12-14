#include <iostream>
using namespace std;
#include <string>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
int main()
{
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.AddEmp();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}	
	system("pause");
	return 0;
}