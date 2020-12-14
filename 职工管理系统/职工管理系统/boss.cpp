#include "boss.h"
Boss::Boss(int id, string name, int did)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}
void Boss::showInfo()
{
	cout << "职工编号:" << m_Id
		<< "\t职工名字:" << m_Name
		<< "\t岗位:" << getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}
string Boss::getDeptName()
{
	return string("老板");
}