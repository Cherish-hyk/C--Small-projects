#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<deque>
#include "speaker.h"
#include<algorithm>
#include<functional>
#include<numeric>
#include<fstream>
using namespace std;
class SpeechManager
{
public:
	SpeechManager();

	void show_Menu();

	void exitSystem();

	~SpeechManager();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	bool fileIsEmpty;

	void showRecord();

	void clearRecord();
	map<int, vector<string>>m_Record;
	vector<int>v;
	vector<int>v1;
	vector<int>vVictory;
	map<int, Speaker>m_Speaker;
	int m_index;
};