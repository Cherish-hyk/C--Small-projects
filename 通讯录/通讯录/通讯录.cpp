#include <iostream>
using namespace std;
#include <string>
#define MAX 1000
//菜单
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};
struct Addressbooks
{
	Person personarray[MAX];
	int m_Size;
};
void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满"<<endl;
	}
	else
	{
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		abs->personarray[abs->m_Size].m_name = name;
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入错误" << endl;
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_Size].m_age = age;
		cout << "请输入联系电话"<<endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_Size].m_phone = phone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_Size].m_addr = address;
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");		
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：  " << abs->personarray[i].m_name << "\t";
			cout << "性别：  " << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：  " << abs->personarray[i].m_age << "\t";
			cout << "电话：  " << abs->personarray[i].m_phone << "\t";
			cout << "地址：  " << abs->personarray[i].m_addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}
void deletePerson(Addressbooks* abs)
{
	cout << "请输入删除联系人姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "没有此联系人" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_Size--;
	}
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入查找联系人姓名" << endl;
	string name;
	cin >> name;
	int i= isExist(abs, name);
	if (i == -1)
	{
		cout << "没有此人" << endl;
	}
	else
	{
		cout << "姓名：  " << abs->personarray[i].m_name << "\t";
		cout << "性别：  " << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：  " << abs->personarray[i].m_age << "\t";
		cout << "电话：  " << abs->personarray[i].m_phone << "\t";
		cout << "地址：  " << abs->personarray[i].m_addr << endl;
	}	
	system("pause");
	system("cls");
}
void modificationPerson(Addressbooks* abs)
{
	cout << "请输入需要修改的联系人姓名" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "没有此人" << endl;
	}
	else
	{
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		abs->personarray[i].m_name = name;
		cout << "请输入性别" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[i].m_sex = sex;
				break;
			}
			cout << "输入错误" << endl;
		}
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[i].m_age = age;
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[i].m_phone = phone;
		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		abs->personarray[i].m_addr = address;
		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "清除成功" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://1、添加联系人
			addPerson(&abs);
			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
			deletePerson(&abs);
			break;
		case 4://4、查找联系人
			findPerson(&abs);
			break;
		case 5://5、修改联系人
			modificationPerson(&abs);
			break;
		case 6://6、清空联系人
			clearPerson(&abs);
			break;
		case 0://0、退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	
	system("pause");
	return 0;
}