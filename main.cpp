#include <iostream>
#include <vector>
#include <chrono>
#include "SmokingStat.h"
#include "SmokingHashMap.h"
#include "SmokingGraph.h"

using namespace std;

int main() {
    // Example data: Replace this with actual data from a file or another source
    vector<SmokingStat> data = {
            // countryName, year, dailyCigs, percentMale, percentFemale, percentTotal, totalSmokers, totalFemaleSmokers, totalMaleSmokers
            {"CountryA", 2020, 20, 40, 30, 35, 1000000, 400000, 600000},
            {"CountryB", 2020, 15, 30, 20, 25, 900000,  300000, 600000},
            {"CountryC", 2020, 10, 20, 10, 15, 800000,  200000, 600000},
            {"CountryD", 2020, 10, 20, 10, 14, 800000,  200000, 600000},
            {"CountryE", 2020, 10, 20, 10, 15, 800000,  200000, 600000},
            {"CountryF", 2020, 10, 20, 10, 9, 800000,  200000, 600000},
            {"CountryG", 2020, 10, 20, 10, 12, 800000,  200000, 600000},
            {"CountryH", 2020, 10, 20, 10, 11, 800000,  200000, 600000},
            {"CountryI", 2020, 10, 20, 10, 10, 800000,  200000, 600000},
            {"CountryJ", 2020, 10, 20, 10, 18, 800000,  200000, 600000},
            {"CountryK", 2020, 10, 20, 10, 30, 800000,  200000, 600000},
            // ... Add more data
    };

    int dataStructureChoice;
    int operationChoice;

    while (true) {
        cout << "Choose a Data Structure to Use: " << endl;
        cout << "#1: Hash Map" << endl;
        cout << "#2: Graph" << endl;
        cout << "Choice: ";

        cin >> dataStructureChoice;

        if (dataStructureChoice != 1 && dataStructureChoice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            continue;
        }

        SmokingHashMap hashMap(data);
        SmokingGraph graph(data);

        while (true) {
            cout << "Choose an Operation to Perform: " << endl;
            cout << "#1: Get Stats for Country/Year" << endl;
            cout << "#2: Bonus Features" << endl;
            cout << "Choice: ";

            cin >> operationChoice;

            if (operationChoice == 1) {
                string countryName;
                int year;
                cout << "Enter the country name: ";
                cin >> countryName;
                cout << "Enter the year: ";
                cin >> year;

                auto start = chrono::high_resolution_clock::now();
                if (dataStructureChoice == 1) {
                    SmokingStat result = hashMap.Search(countryName, year);
                    if (result.GetYear() != -1) {
                        cout << result << endl;
                    } else {
                        cout << "Not found." << endl;
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

                cout << "Enter the year: ";
                cin >> year;

                // Note: Implement the functions for Top 10 Least and Most Smoking Countries in the respective classes
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
        }
    }
}
