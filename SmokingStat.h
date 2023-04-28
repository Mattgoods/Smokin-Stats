#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

class SmokingStat
{
private:
    string countryName;

    int year;

    // Average amount of cigarettes smoked per day by smokers
    double dailyCigs;

    // Percentage of the male population who are smokers
    double percentMale;

    // Percentage of the female population who are smokers
    double percentFemale;

    // Percentage of the total population who are smokers
    double percentTotal;

    // Total number smokers
    int totalSmokers;

    int totalFemaleSmokers;

    int totalMaleSmokers;

public:
    SmokingStat() = default;

    SmokingStat(string countryName, int year, double dailyCigs, double percentMale, double percentFemale,
                double percentTotal, int totalSmokers, int totalFemaleSmokers, int totalMaleSmokers);

    friend ostream& operator<<(ostream& os, const SmokingStat& stat) {
        os << "Country: " << stat.countryName << ", Year: " << stat.year << endl
            << "Daily Cigs: " << stat.dailyCigs << endl
            << "Percent Male: " << stat.percentMale << endl
            << "Percent Female: " << stat.percentFemale << endl
            << "Percent Total: " << stat.percentTotal << endl
            << "Total Smokers : " << stat.totalSmokers << endl
            << "Total Female Smokers: " << stat.totalFemaleSmokers << endl
            << "Total Male Smokers: " << stat.totalMaleSmokers << endl;
        return os;
    }

    string GetCountryName() const;

    int GetYear() const;

    double GetDailyCigs() const;

    double GetPercentMale() const;

    double GetPercentFemale() const;

    double GetPercentTotal() const;

    int GetTotalSmokers() const;

    int GetTotalFemaleSmokers() const;

    int TotalMaleSmokers() const;
};
