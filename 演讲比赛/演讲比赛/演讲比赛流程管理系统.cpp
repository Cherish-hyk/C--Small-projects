#include <iostream>
using namespace std;
#include <string>
#include "speechManager.h"
#include<ctime>
int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it!=sm.m_Speaker.end();it++)
	//{
	//	cout << "ѡ�ֱ��: " << it->first << " ������ " << it->second.m_name << " ������ " << it->second.m_score[1] << endl;
	//}
	int choice = 0;
	while (true)
	{
		sm.show_Menu();
		cout << "���������ѡ��>>" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.startSpeech();
			break;
		case 2:
			sm.showRecord();
			break;
		case 3:
			sm.clearRecord();
			break;
		case 0:
			sm.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}