#include "employee.h"


Employee::Employee(int id, string name, int did)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}
void Employee::showInfo()
{
	cout << "职工编号:" << m_Id
		<< "\t职工名字:" << m_Name
		<< "\t岗位:" << getDeptName()
		<< "\t岗位职责：完成经理交给的任务" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
}