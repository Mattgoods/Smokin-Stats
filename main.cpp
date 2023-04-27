#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>
#include <sstream>
#include "SmokingStat.h"
#include "SmokingHashMap.h"

using namespace std;

void ReadFile(ifstream& inFile, vector<SmokingStat>& v);

int main()
{
	ifstream inFile("SmokinStats/smoking.csv");
	vector<SmokingStat> v;
	
	ReadFile(inFile, v);

	for (auto i : v) {

		cout << i.GetCountryName() << ": " << i.GetYear() << endl;
	}

	SmokingHashMap HashMap(v);

}


void ReadFile(ifstream& inFile, vector<SmokingStat>& v)
{
	if (inFile.is_open())
	{
		// line from file (lff)
		string lff;
		string buffer;
		string countryName;
		int year;
		double dailyCigs, percentMale, percentFemale, percentTotal;
		int totalSmokers, totalFemaleSmokers, totalMaleSmokers;
		getline(inFile, lff);
		while (getline(inFile, lff))
		{
			//cout << lff << endl;
			istringstream stream(lff);
			getline(stream, countryName, ',');
			
			getline(stream, buffer, ',');
			//buffer = buffer.substr(1, buffer.length() - 2);
			year = stoi(buffer);

			getline(stream, buffer, ',');
			dailyCigs = stof(buffer);

			getline(stream, buffer, ',');
			percentMale = stof(buffer);

			getline(stream, buffer, ',');
			percentFemale = stof(buffer);

			getline(stream, buffer, ',');
			percentTotal = stof(buffer);

			getline(stream, buffer, ',');
			totalSmokers = stoi(buffer);

			getline(stream, buffer, ',');
			totalFemaleSmokers = stoi(buffer);

			getline(stream, buffer, ',');
			totalMaleSmokers = stoi(buffer);
			/*SmokingStat s(countryName, year, dailyCigs, percentMale, percentFemale, 
				percentTotal, totalSmokers, totalFemaleSmokers, totalMaleSmokers);*/
			v.push_back(SmokingStat(countryName, year, dailyCigs, percentMale, percentFemale,
				percentTotal, totalSmokers, totalFemaleSmokers, totalMaleSmokers));
		}
	}

}
