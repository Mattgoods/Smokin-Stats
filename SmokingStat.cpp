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

string SmokingStat::GetCountryName()
{
	return countryName;
}

int SmokingStat::GetYear()
{
	return year;
}

double SmokingStat::GetDailyCigs()
{
	return dailyCigs;
}

double SmokingStat::GetPercentMale()
{
	return percentMale;
}

double SmokingStat::GetPercentFemale()
{
	return percentFemale;
}

double SmokingStat::GetPercentTotal()
{
	return percentTotal;
}

int SmokingStat::GetTotalSmokers()
{
	return totalSmokers;
}

int SmokingStat::GetTotalFemaleSmokers()
{
	return totalFemaleSmokers;
}

int SmokingStat::TotalMaleSmokers()
{
	return totalMaleSmokers;
}
