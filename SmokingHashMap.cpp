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

SmokingStat SmokingHashMap::Search(const std::string &countryName, int year) {
    int index = Hash(countryName, year) % size; // Add modulo with the size of the hash table
    for (const auto &entry : hashTable[index]) {
        if (entry.GetCountryName() == countryName && entry.GetYear() == year) {
            return entry;
        }
    }

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

vector<SmokingStat> SmokingHashMap::Top10LeastSmokingCountries(int year)
{
    vector<SmokingStat> top10Least;
    for (const vector<SmokingStat> &bucket : hashTable) {
        for (const SmokingStat &entry: bucket) {

            if (entry.GetYear() == year) {
                top10Least.push_back(entry);
            }
        }
    }
    sort(top10Least.begin(), top10Least.end(), [](const SmokingStat &a, const SmokingStat &b) { return a.GetPercentTotal() < b.GetPercentTotal(); });

    if (top10Least.size() > 10)
    {
        top10Least.resize(10);
    }

    for (size_t i = 0; i < top10Least.size(); ++i) {
        const auto &stat = top10Least[i];
        cout << "#" << (i + 1) << " - " << stat.GetCountryName() << ": " << stat.GetPercentTotal() << "%" << endl;
    }
    return top10Least;
}

vector<SmokingStat> SmokingHashMap::Top10MostSmokingCountries(int year)
{
    vector<SmokingStat> top10Most;
    for (const vector<SmokingStat> &bucket : hashTable) {
        for (const SmokingStat &entry : bucket) {
            if (entry.GetYear() == year) {
                top10Most.push_back(entry);
            }
        }
    }

    sort(top10Most.begin(), top10Most.end(), [](const SmokingStat &a, const SmokingStat &b) { return a.GetPercentTotal() > b.GetPercentTotal(); });

    if (top10Most.size() > 10)
    {
        top10Most.resize(10);
    }
    for (size_t i = 0; i < top10Most.size(); ++i) {
        const auto &stat = top10Most[i];
        cout << "#" << (i + 1) << " - " << stat.GetCountryName() << ": " << stat.GetPercentTotal() << "%" << endl;
    }
    return top10Most;
}
