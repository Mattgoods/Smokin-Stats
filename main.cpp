#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>
#include <sstream>
#include "SmokingStat.h"
#include "SmokingHashMap.h"
#include "SmokingGraph.h"
#include <chrono>
#include <thread>

using namespace std;

// used to read data
void ReadFile(ifstream& inFile, vector<SmokingStat>& v);


int main() {

    auto fiveSeconds = 5s;
    this_thread::sleep_for(fiveSeconds);

    cout << "Smokin' Stats Project" << endl;
    cout << "Made by Roshan Ahmed, Matt Goodman, and Sharan Majumder " << endl;

    // Example data: Replace w/ actual data
    //vector<SmokingStat> data = {
    //        // countryName, year, dailyCigs, percentMale, percentFemale, percentTotal, totalSmokers, totalFemaleSmokers, totalMaleSmokers
    //        {"CountryA", 2020, 20, 40, 30, 35, 1000000, 400000, 600000},
    //        {"CountryB", 2020, 15, 30, 20, 25, 900000,  300000, 600000},
    //        {"CountryC", 2020, 10, 20, 10, 15, 800000,  200000, 600000},
    //        {"CountryD", 2020, 10, 20, 10, 14, 800000,  200000, 600000},
    //        {"CountryE", 2020, 10, 20, 10, 15, 800000,  200000, 600000},
    //        {"CountryF", 2020, 10, 20, 10, 9, 800000,  200000, 600000},
    //        {"CountryG", 2020, 10, 20, 10, 12, 800000,  200000, 600000},
    //        {"CountryH", 2020, 10, 20, 10, 11, 800000,  200000, 600000},
    //        {"CountryI", 2020, 10, 20, 10, 10, 800000,  200000, 600000},
    //        {"CountryJ", 2020, 10, 20, 10, 18, 800000,  200000, 600000},
    //        {"CountryK", 2020, 10, 20, 10, 30, 800000,  200000, 600000},
    //        // ... Add more data
    //};

    // open and read data points
    ifstream inFile("smoking.csv");
    vector<SmokingStat> data;
    ReadFile(inFile, data);

    int dataStructureChoice;
    int operationChoice;
    
    // determine when to exit program
    bool running = true;
    cout << endl;

    // start running the program
    while (running) {

        // Ask user what DS to use
        cout << "========================================" << endl;
        cout << "Choose a Data Structure to Use: " << endl;
        cout << "#1: Hash Map" << endl;
        cout << "#2: Graph" << endl;
        cout << "#3: Quit" << endl;
        cout << "Choice: ";

        cin >> dataStructureChoice;
        cout << endl;

        if (dataStructureChoice == 3)
        {
            running = false;
            break;
        }

        // if choice is invalid, pick again
        if (dataStructureChoice != 1 && dataStructureChoice != 2 && dataStructureChoice != 3) {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            continue;
        }

        SmokingHashMap hashMap(data);
        SmokingGraph graph(data);


        cout << "Choose an Operation to Perform: " << endl;
        cout << "#1: Get Stats for Country/Year" << endl;
        cout << "#2: Bonus Features" << endl;
        cout << "Choice: ";

        cin >> operationChoice;

        if (operationChoice == 1) {
            string countryName;
            int year;
            cout << "Enter the country name: ";
            cin.ignore();
            getline(cin, countryName);
            //system("pause");
            cout << "Enter the year (1980-2012): ";
            //cin.ignore();
            cin >> year;
            cout << endl;
            if (year < 1980 || year > 2012)
            {
                cout << "Invalid year, please input between 1980-2012" << endl;
                continue;
            }
            auto start = chrono::high_resolution_clock::now();

            if (dataStructureChoice == 1) {
                try
                {
                    try
                    {
                        SmokingStat result = hashMap.Search(countryName, year);
                        if (result.GetYear() != -1) {
                            cout << result << endl;
                        }
                        else {
                            cout << "Not found." << endl;
                        }
                    }
                    catch (const runtime_error& e)
                    {
                        cerr << e.what() << endl;

                    }
                }
                catch (const runtime_error &e)
                {
                    cerr << e.what() << endl;
                }
                
                
            } else {
                try {
                    try {
                        SmokingStat result = graph.GetVertex(countryName, year);
                        if (result.GetYear() != -1) {
                            cout << result << endl;
                        } else {
                            cout << "Not found." << endl;
                        }
                    } catch (const runtime_error &e) {
                        cerr << e.what() << endl;
                    }

                }
                catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                }
            }

            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;

        } else if (operationChoice == 2) {
            int bonusFeatureChoice;
            int year;

            cout << "Choose a Bonus Feature: " << endl;
            cout << "#1: Top 10 Least Smoking Countries" << endl;
            cout << "#2: Top 10 Most Smoking Countries" << endl;
            cout << "Choice: ";

            cin >> bonusFeatureChoice;

            if (bonusFeatureChoice != 1 && bonusFeatureChoice != 2) {
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                continue;
            }

            cout << "Enter the year (1980-2012): ";
            cin >> year;

            auto start = chrono::high_resolution_clock::now();
            if (dataStructureChoice == 1) {
                if (bonusFeatureChoice == 1) {
                    hashMap.Top10LeastSmokingCountries(year);
                } else {
                    hashMap.Top10MostSmokingCountries(year);
                }
            } else {
                if (bonusFeatureChoice == 1) {
                    graph.Top10LeastSmokingCountries(year);
                } else {
                    graph.Top10MostSmokingCountries(year);
                }
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;
        }
        this_thread::sleep_for(fiveSeconds);

    }
    cout << "Program exited" << endl;
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
