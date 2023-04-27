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

    void Insert(int index, SmokingStat stat);
    unsigned long long Hash(string countryName, short year);
public:
    SmokingHashMap(vector<SmokingStat>& v);
    void Search(string countryName, int year);
    void Print();
    void PrintGreatestNum();
    void PrintFewestNum();
    void PrintLargestPercent();
    void PrintSmallestPercent();

};