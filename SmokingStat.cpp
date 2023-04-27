#include "SmokingStat.h"

SmokingStat::SmokingStat(string countryName, int year, double dailyCigs, double percentMale, double percentFemale,
                         double percentTotal, int totalSmokers, int totalFemaleSmokers, int totalMaleSmokers)
{
    this->countryName = countryName;
    this->year = year;
    this->dailyCigs = dailyCigs;
    this->percentMale = percentMale;
    this->percentFemale = percentFemale;
    this->percentTotal = percentTotal;
    this->totalSmokers = totalSmokers;
    this->totalFemaleSmokers = totalFemaleSmokers;
    this->totalMaleSmokers = totalMaleSmokers;

}

string SmokingStat::GetCountryName() const
{
    return countryName;
}

int SmokingStat::GetYear() const
{
    return year;
}

double SmokingStat::GetDailyCigs() const
{
    return dailyCigs;
}

double SmokingStat::GetPercentMale() const
{
    return percentMale;
}

double SmokingStat::GetPercentFemale() const
{
    return percentFemale;
}

double SmokingStat::GetPercentTotal() const
{
    return percentTotal;
}

int SmokingStat::GetTotalSmokers() const
{
    return totalSmokers;
}

int SmokingStat::GetTotalFemaleSmokers() const
{
    return totalFemaleSmokers;
}

int SmokingStat::TotalMaleSmokers() const
{
    return totalMaleSmokers;
}
