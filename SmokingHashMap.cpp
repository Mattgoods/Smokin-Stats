#include "SmokingHashMap.h"
#include <chrono>

unsigned long long SmokingHashMap::Hash(string countryName, short year)
{
    unsigned long long hashVal = 0;
    int power = 1;
    if (countryName.length() < 15)
    {
        for (auto i : countryName)
        {
            hashVal += power * i;
            power *= 2;
        }
    }
    else
    {
        for (int i = 0; i < 15; i++)
        {
            hashVal += power * countryName[i];
            power *= 2;

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

void SmokingHashMap::Search(string countryName, int year)
{
    int index = Hash(countryName, year) % size;
    bool found = false;
    for (auto i : hashTable[index])
    {
        if (i.GetCountryName() == countryName && i.GetYear() == year)
        {
            found = true;
        }
    }

    if (found)
        cout << "Found!";
    else
        cout << "Not found!";
}

void SmokingHashMap::Print()
{
    int a = 0;
    for (auto i : hashTable)
    {
        for (auto j : i)
        {
            cout << j.GetCountryName() << ", " << j.GetYear() << ": " << j.GetTotalSmokers() << endl;
            //a++;
        }
        //	cout << "-----" << endl;
    }
    //cout << a;
}

void SmokingHashMap::PrintGreatestNum()
{
    chrono::steady_clock::time_point start = chrono::high_resolution_clock::now();
    int num = 0;
    int a = 0, b = 0;
    int x = 0, y = 0;

    for (auto i : hashTable)
    {
        b = 0;
        for (auto j : i)
        {
            if (j.GetTotalSmokers() > num)
            {
                num = j.GetTotalSmokers();
                x = a;
                y = b;
            }
            //cout << j.GetCountryName() << ", " << j.GetYear() << ": " << j.GetTotalSmokers() << endl;
            b++;
        }
        a++;
    }
    chrono::steady_clock::time_point end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Time took " << duration.count() << " microseconds" << endl;
    cout << hashTable[x][y].GetCountryName() << hashTable[x][y].GetYear();
}

void SmokingHashMap::PrintFewestNum()
{

}

void SmokingHashMap::PrintLargestPercent()
{

}

void SmokingHashMap::PrintSmallestPercent()
{

}