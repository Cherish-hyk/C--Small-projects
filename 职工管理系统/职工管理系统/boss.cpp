#include "boss.h"
Boss::Boss(int id, string name, int did)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}
void Boss::showInfo()
{
	cout << "ְ�����:" << m_Id
		<< "\tְ������:" << m_Name
		<< "\t��λ:" << getDeptName()
		<< "\t��λְ�𣺹���˾��������" << endl;
}
string Boss::getDeptName()
{
	return string("�ϰ�");
}