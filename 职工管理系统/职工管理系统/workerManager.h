#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"
#include <fstream>
#define FILENAME "employee.txt"
class WorkerManager
{
public:
	WorkerManager();
	void Show_Menu();
	void ExitSystem();
	void Save();
	void ShowEmp();
	bool m_FileIsEmpty;
	int get_EmpNum();
	void Del_Emp();
	int IsExist(int id);
	void Mod_Emp();
	void Find_Emp();
	void Sort_Emp();
	void init_Emp();
	void Clean_File();
	~WorkerManager();
	int m_EmpNum;
	Worker** m_EmpArray;
	void AddEmp();
};