#pragma once
#include <vector>
#include <list>
#include "SmokingStat.h"

using namespace std;

class SmokingHashMap
{
private:
	/*struct Node
	{
		SmokingStat stat;
		Node* next = nullptr;
	};*/

	int size;

	vector<vector<SmokingStat>> hashTable;

public:
	SmokingHashMap(vector<SmokingStat>& v);
	unsigned long long Hash(string countryName, short year);
	void Insert(int index, SmokingStat stat);
	void Search();
};

