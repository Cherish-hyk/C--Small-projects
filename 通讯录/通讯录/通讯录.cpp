#include <iostream>
using namespace std;
#include <string>
#define MAX 1000
//�˵�
void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
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
		cout << "ͨѶ¼����"<<endl;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[abs->m_Size].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "�������" << endl;
		}
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_Size].m_age = age;
		cout << "��������ϵ�绰"<<endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_Size].m_phone = phone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_Size].m_addr = address;
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");		
	}
}
void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������  " << abs->personarray[i].m_name << "\t";
			cout << "�Ա�  " << (abs->personarray[i].m_sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺  " << abs->personarray[i].m_age << "\t";
			cout << "�绰��  " << abs->personarray[i].m_phone << "\t";
			cout << "��ַ��  " << abs->personarray[i].m_addr << endl;
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
	cout << "������ɾ����ϵ������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "û�д���ϵ��" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->m_Size--;
	}
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "�����������ϵ������" << endl;
	string name;
	cin >> name;
	int i= isExist(abs, name);
	if (i == -1)
	{
		cout << "û�д���" << endl;
	}
	else
	{
		cout << "������  " << abs->personarray[i].m_name << "\t";
		cout << "�Ա�  " << (abs->personarray[i].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺  " << abs->personarray[i].m_age << "\t";
		cout << "�绰��  " << abs->personarray[i].m_phone << "\t";
		cout << "��ַ��  " << abs->personarray[i].m_addr << endl;
	}	
	system("pause");
	system("cls");
}
void modificationPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ������" << endl;
	string name;
	cin >> name;
	int i = isExist(abs, name);
	if (i == -1)
	{
		cout << "û�д���" << endl;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personarray[i].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[i].m_sex = sex;
				break;
			}
			cout << "�������" << endl;
		}
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[i].m_age = age;
		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personarray[i].m_phone = phone;
		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		abs->personarray[i].m_addr = address;
		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void clearPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "����ɹ�" << endl;
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
		case 1://1�������ϵ��
			addPerson(&abs);
			break;
		case 2://2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://4��������ϵ��
			findPerson(&abs);
			break;
		case 5://5���޸���ϵ��
			modificationPerson(&abs);
			break;
		case 6://6�������ϵ��
			clearPerson(&abs);
			break;
		case 0://0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		}
	}
	
	system("pause");
	return 0;
}