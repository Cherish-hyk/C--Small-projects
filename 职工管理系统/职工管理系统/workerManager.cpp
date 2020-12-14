#include "workerManager.h"
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!(ifs.is_open()))
	{
		//cout << "文件不存在" << endl;
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
	//	cout << "文件为空!" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = get_EmpNum();
	//cout << "职工人数为：" << num << endl;
	m_EmpNum = num;
	m_EmpArray = new Worker * [m_EmpNum];
	init_Emp();
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "职工编号：" << m_EmpArray[i]->m_Id
			<< "\t姓名：" << m_EmpArray[i]->m_Name
			<< "\t部门编号：" <<m_EmpArray[i]->m_DeptId<< endl;
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
	cout << "*****  欢迎使用职工管理系统  *****" << endl;
	cout << "********* 0.退出管理系统 *********" << endl;
	cout << "********* 1.增加职工信息 *********" << endl;
	cout << "********* 2.显示职工信息 *********" << endl;
	cout << "********* 3.删除离职职工 *********" << endl;
	cout << "********* 4.修改职工信息 *********" << endl;
	cout << "********* 5.查找职工信息 *********" << endl;
	cout << "********* 6.按照编号排序 *********" << endl;
	cout << "********* 7.清空所有文档 *********" << endl;
	cout << "**********************************" << endl;
	cout <<  endl;
}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp()
{
	cout << "请输入添加员工数量：" << endl;
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
			cout << "请输入第" << i + 1 << "个新职工的编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工的名字：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
		cout << "成功添加" << addNum << "名新职工!" << endl;
		Save();
	}
	else
	{
		cout << "输入有误" << endl;
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
		cout << "文件不存在或文件为空!" << endl;
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
		cout << "文件不存在或文件为空!" << endl;
	}
	else
	{
		cout << "请输入想要删除职工的编号:" << endl;
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
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "未找到该职工" << endl;
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
		cout << "文件不存在或文件为空!" << endl;
	}
	else
	{
		cout << "请输入想要修改职工的编号:" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			delete m_EmpArray[ret];
			int newId=0;
			string newName = "";
			int dSelect = 0;
			cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
			cin >> newId;
			cout << "请输入新名字：" << endl;
			cin >> newName;
			cout << "请输入该职工的新岗位：" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			cout << "修改成功" << endl;
			Save();

		}
		else
		{
			cout << "没有此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空!" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按照职工编号查找" << endl;
		cout << "2.按照职工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "请输入想要查找职工的编号:" << endl;
			int id = 0;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，此人的信息为：" << endl;
				m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "没有此人" << endl;
			}
		}
		else if(select==2)
		{
			string name;
			cout << "请输入查找的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,员工信息如下" << endl;
					flag = true;
					m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << " 查找失败" << endl;
			}
		}
		else
		{
			cout << "输入错误" << endl;

		}
	}
		system("pause");
		system("cls");
}
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空!" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按照职工号进行升序排列" << endl;
		cout << "2.按照职工号进行降序排列" << endl;
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
		cout << "排序成功！排序后的结果为：" << endl;
		Save();
		ShowEmp();
	}
}
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
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
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}