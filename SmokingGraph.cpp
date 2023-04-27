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

void SmokingGraph::PrintGreatestNum()
{
    SmokingStat maxStat;
    bool first = true;

    for (const auto& entry : graph)
    {
        if (first || entry.second.GetTotalSmokers() > maxStat.GetTotalSmokers())
        {
            maxStat = entry.second;
            first = false;
        }
    }

    cout << "Country with greatest number of smokers: " << maxStat.GetCountryName() << " (" << maxStat.GetYear() << ") with " << maxStat.GetTotalSmokers() << " smokers" << endl;
}

void SmokingGraph::PrintFewestNum()
{
    SmokingStat minStat;
    bool first = true;

    for (const auto& entry : graph)
    {
        if (first || entry.second.GetTotalSmokers() < minStat.GetTotalSmokers())
        {
            minStat = entry.second;
            first = false;
        }
    }

    cout << "Country with fewest number of smokers: " << minStat.GetCountryName() << " (" << minStat.GetYear() << ") with " << minStat.GetTotalSmokers() << " smokers" << endl;
}

void SmokingGraph::PrintLargestPercent()
{
    SmokingStat maxStat;
    bool first = true;

    for (const auto& entry : graph)
    {
        if (first || entry.second.GetPercentTotal() > maxStat.GetPercentTotal())
        {
            maxStat = entry.second;
            first = false;
        }
    }

    cout << "Country with largest percent of smokers: " << maxStat.GetCountryName() << " (" << maxStat.GetYear() << ") with " << maxStat.GetPercentTotal() << "% smokers" << endl;
}

void SmokingGraph::PrintSmallestPercent()
{
    SmokingStat minStat;
    bool first = true;

    for (const auto& entry : graph)
    {
        if (first || entry.second.GetPercentTotal() < minStat.GetPercentTotal())
        {
            minStat = entry.second;
            first = false;
        }
    }

    cout << "Country with smallest percent of smokers: " << minStat.GetCountryName() << " (" << minStat.GetYear() << ") with " << minStat.GetPercentTotal() << "% smokers" << endl;
}
