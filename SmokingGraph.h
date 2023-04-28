#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "SmokingStat.h"

using namespace std;

class SmokingGraph
{
private:
    map<pair<string, int>, SmokingStat> graph;

public:
    SmokingGraph(vector<SmokingStat>& v);

    void AddVertex(const SmokingStat& stat);

    SmokingStat GetVertex(const string& countryName, int year);

    void PrintGreatestNum();

    void PrintFewestNum();

    void PrintLargestPercent();

    void PrintSmallestPercent();

    vector<SmokingStat> Top10LeastSmokingCountries(int year);

    vector<SmokingStat> Top10MostSmokingCountries(int year);

};
