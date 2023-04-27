#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "SmokingStat.h"

using namespace std;

class SmokingGraph
{
private:
    map<string, SmokingStat> graph;

public:
    SmokingGraph(vector<SmokingStat>& v);

    void AddVertex(const SmokingStat& stat);

    SmokingStat GetVertex(const string& countryName);
};
