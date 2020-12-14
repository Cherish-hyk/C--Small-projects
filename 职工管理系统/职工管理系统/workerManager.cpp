#include "workerManager.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!(ifs.is_open()))
	{
		//cout << "�ļ�������" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
	//	cout << "�ļ�Ϊ��!" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = get_EmpNum();
	//cout << "ְ������Ϊ��" << num << endl;
	m_EmpNum = num;
	m_EmpArray = new Worker * [m_EmpNum];
	init_Emp();
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << m_EmpArray[i]->m_Id
			<< "\t������" << m_EmpArray[i]->m_Name
			<< "\t���ű�ţ�" <<m_EmpArray[i]->m_DeptId<< endl;
	}*/
}
WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
				delete m_EmpArray[i];
		}
		delete[]m_EmpArray;
		m_EmpArray = NULL;
	}
}
void WorkerManager::Show_Menu()
{
	cout << "**********************************" << endl;
	cout << "*****  ��ӭʹ��ְ������ϵͳ  *****" << endl;
	cout << "********* 0.�˳�����ϵͳ *********" << endl;
	cout << "********* 1.����ְ����Ϣ *********" << endl;
	cout << "********* 2.��ʾְ����Ϣ *********" << endl;
	cout << "********* 3.ɾ����ְְ�� *********" << endl;
	cout << "********* 4.�޸�ְ����Ϣ *********" << endl;
	cout << "********* 5.����ְ����Ϣ *********" << endl;
	cout << "********* 6.���ձ������ *********" << endl;
	cout << "********* 7.��������ĵ� *********" << endl;
	cout << "**********************************" << endl;
	cout <<  endl;
}
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp()
{
	cout << "���������Ա��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = m_EmpNum + addNum;
		Worker**newspace= new Worker* [newSize];
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newspace[i] = m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ���ı�ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����ְ�������֣�" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newspace[m_EmpNum + i] = worker;
		}
		delete[]m_EmpArray;
		m_EmpArray = newspace;
		m_EmpNum = newSize;
		m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ��!" << endl;
		Save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void  WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_Id << "  "
			<< m_EmpArray[i]->m_Name << "  "
			<< m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();
}
void WorkerManager::ShowEmp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs>>id&&ifs>>name&&ifs>>did)
	{
		num++;
	}
	return num;
}
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else 
		{
			worker = new Boss(id, name, did);
		}
		m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}
void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫɾ��ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			for (int i = ret; i < m_EmpNum-1; i++)
			{
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			m_EmpNum--;
			Save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸�ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			delete m_EmpArray[ret];
			int newId=0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
			cin >> newId;
			cout << "�����������֣�" << endl;
			cin >> newName;
			cout << "�������ְ�����¸�λ��" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			Save();

		}
		else
		{
			cout << "û�д���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "��������Ҫ����ְ���ı��:" << endl;
			int id = 0;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ������˵���ϢΪ��" << endl;
				m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "û�д���" << endl;
			}
		}
		else if(select==2)
		{
			string name;
			cout << "��������ҵ�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,Ա����Ϣ����" << endl;
					flag = true;
					m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << " ����ʧ��" << endl;
			}
		}
		else
		{
			cout << "�������" << endl;

		}
	}
		system("pause");
		system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1.����ְ���Ž�����������" << endl;
		cout << "2.����ְ���Ž��н�������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = 1;
			for (int j = i + 1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		Save();
		ShowEmp();
	}
}
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
			delete[]m_EmpArray;
			m_EmpArray = NULL;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
		}	
		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}