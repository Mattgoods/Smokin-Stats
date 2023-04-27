#include "SmokingGraph.h"

SmokingGraph::SmokingGraph(vector<SmokingStat>& v)
{
    for (const auto& stat : v)
    {
        string countryName = stat.GetCountryName();
        graph.emplace(countryName, stat);
    }
}

void SmokingGraph::AddVertex(const SmokingStat& stat)
{
    string countryName = stat.GetCountryName();
    graph[countryName] = stat;
}

SmokingStat SmokingGraph::GetVertex(const string& countryName)
{
    if (graph.find(countryName) != graph.end())
    {
        return graph[countryName];
    }
    else
    {
        throw runtime_error("Country not found in the graph");
    }
}
