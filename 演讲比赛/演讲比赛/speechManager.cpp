#include "speechManager.h"
SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}
void SpeechManager::show_Menu()
{
	cout << "******************************" << endl;
	cout << "****** 欢迎参加演讲比赛 ******" << endl;
	cout << "******  1.开始演讲比赛  ******" << endl;
	cout << "******  2.查看往届记录  ******" << endl;
	cout << "******  3.清空比赛记录  ******" << endl;
	cout << "******  0.退出比赛流程  ******" << endl;
	cout << "******************************" << endl;
	cout << endl;
}
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_score[j] = 0;
		}
		this->v.push_back(i + 10001);
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}
void SpeechManager::initSpeech()
{
	this->v.clear();
	this->v1.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_index = 1;
	this->m_Record.clear();
}
void SpeechManager::startSpeech()
{
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->m_index++;
	this->speechDraw();
	this->speechContest();
	this->showScore();
	this->saveRecord();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "本届比赛结束！！！" << endl;
	system("pause");
	system("cls");
}
void SpeechManager::speechDraw()
{
	cout << "第" << this->m_index << "轮比赛选手正在抽签" << endl;
	cout << "--------------------------------" << endl;
	cout << "抽签后的演出顺序如下：" << endl;
	if (this->m_index == 1)
	{
		random_shuffle(v.begin(), v.end());
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------" << endl;
	system("pause");
	cout << endl;
}
void SpeechManager::speechContest()
{
	cout << "------第" << this->m_index << "轮比赛正式开始------" << endl;
	vector<int>v_Src;
	multimap<double, int, greater<double>>groupScore;
	int num = 0;
	if (this->m_index == 1)
	{
		v_Src = v;
	}
	else
	{
		v_Src = v1;
	}
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		deque<double>d;
		for (int i = 0; i < v_Src.size(); i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;
		sort(d.begin(), d.end(), greater<double>());
		d.pop_front();
		d.pop_back();
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		this->m_Speaker[*it].m_score[this->m_index - 1] = avg;
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << "姓名： " << this->m_Speaker[it->second].m_name
					<< "成绩: " << this->m_Speaker[it->second].m_score[this->m_index-1] << endl;
			}
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_index == 1)
				{
					v1.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "------第" << this->m_index << "轮比赛完毕!!!------" << endl;
	system("pause");
	system("cls");
}
void SpeechManager::showScore()
{
	cout << "------第" << this->m_index << "轮晋级选手信息------" << endl;
	vector<int>v2;
	if (this->m_index == 1)
	{
		v2 = v1;
	}
	else
	{
		v2 = vVictory;
	}
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << "选手编号： " << *it << " 姓名： " << this->m_Speaker[*it].m_name
			<< " 得分： " << this->m_Speaker[*it].m_score[this->m_index - 1] << endl;

	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->m_Speaker[*it].m_score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "成绩已经保存完成！" << endl;
	this->fileIsEmpty = false;
}
void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);
	
	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	this->fileIsEmpty = false;
	ifs.putback(ch);
	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>s;
		int pos = -1;
		int start = 0;
		while (1)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			s.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, s));
		index++;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << "冠军编号：" << it->second[0]
	}*/
}
void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者不存在" << endl;
	}
	for (int i = 0; i < this->m_Record.size(); i++)
	{
		cout << "第" << i + 1 << "届"
			<< "冠军编号：" << this->m_Record[i][0] << " \t得分：" << this->m_Record[i][1]
			<< "\t亚军编号：" << this->m_Record[i][2] << " \t得分：" << this->m_Record[i][3]
			<< "\t季军编号：" << this->m_Record[i][4] << " \t得分：" << this->m_Record[i][5]<<endl;
	}
	system("pause");
	system("cls");
}
void SpeechManager::clearRecord()
{
	cout << "清空数据？" << endl;
	cout << "1.确定" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		this->initSpeech();
		this->createSpeaker();
		this->loadRecord();
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}
SpeechManager::~SpeechManager()
{

}