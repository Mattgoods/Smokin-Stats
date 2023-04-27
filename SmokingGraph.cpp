#include "SmokingGraph.h"

SmokingGraph::SmokingGraph(vector<SmokingStat>& v)
{
    for (const auto& stat : v)
    {
        string countryName = stat.GetCountryName();
        int year = stat.GetYear();
        graph.emplace(make_pair(countryName, year), stat);
    }
}

void SmokingGraph::AddVertex(const SmokingStat& stat)
{
    string countryName = stat.GetCountryName();
    int year = stat.GetYear();
    graph[make_pair(countryName, year)] = stat;
}

SmokingStat SmokingGraph::GetVertex(const string& countryName, int year)
{
    auto key = make_pair(countryName, year);
    if (graph.find(key) != graph.end())
    {
        return graph[key];
    }
    else
    {
        throw runtime_error("Country and year not found in the graph");
    }
}
