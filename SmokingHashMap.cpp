#include "SmokingHashMap.h"

unsigned long long SmokingHashMap::Hash(string countryName, short year)
{
	unsigned long long hashVal = 0;
	int power = 1;
	if (countryName.length() < 15)
	{
		for (auto i : countryName)
		{
			hashVal += power * i;
		}
	}
	else
	{
		for (int i = 0; i < 15; i++)
		{
			hashVal += power * countryName[i];
		}
	}
	return hashVal + year;
}

void SmokingHashMap::Insert(int index, SmokingStat stat)
{
	/*if (hashTable[index] == nullptr)
		hashTable[index] = node;
	else
	{
		Node* temp = hashTable[index];
		while (temp->next == nullptr)
		{
			temp = temp->next;
		}
		temp->next = node;
	}*/

	hashTable[index].push_back(stat);
}


SmokingHashMap::SmokingHashMap(vector<SmokingStat>& v)
{
	this->size = v.size();
	hashTable.resize(size);


	for (auto& i : v)
	{
		int index = Hash(i.GetCountryName(), i.GetYear()) % size;
		Insert(index, i);
	}
}