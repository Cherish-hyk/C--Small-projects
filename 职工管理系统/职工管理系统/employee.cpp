#include "employee.h"


Employee::Employee(int id, string name, int did)
{
	m_Id = id;
	m_Name = name;
	m_DeptId = did;
}
void Employee::showInfo()
{
	cout << "ְ�����:" << m_Id
		<< "\tְ������:" << m_Name
		<< "\t��λ:" << getDeptName()
		<< "\t��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}