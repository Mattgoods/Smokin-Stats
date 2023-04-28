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

vector<SmokingStat> SmokingGraph::Top10LeastSmokingCountries(int year)
{
    vector<SmokingStat> top10Least;
    for (const auto &entry : graph)
    {
        if (entry.first.second == year)
        {
            top10Least.push_back(entry.second);
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

vector<SmokingStat> SmokingGraph::Top10MostSmokingCountries(int year)
{
    vector<SmokingStat> top10Most;
    for (const auto &entry : graph)
    {
        if (entry.first.second == year)
        {
            top10Most.push_back(entry.second);
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
