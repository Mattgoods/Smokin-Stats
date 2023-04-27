#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>
#include <sstream>
#include "SmokingStat.h"
#include "SmokingHashMap.h"
#include <time.h>
#include <chrono>
/*
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
*/
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

using namespace std;


void ReadFile(ifstream& inFile, vector<SmokingStat>& v);

void PromptChoices();

void PromptSearches();

void AskName();

void AskYear();

int main()
{
    // auto start = chrono::high_resolution_clock::now();

    // chrono::steady_clock::time_point a = chrono::high_resolution_clock::now();

    ifstream inFile("smoking.csv");
    vector<SmokingStat> v;

    ReadFile(inFile, v);

    /*for (auto i : v)
    {
        cout << i.GetCountryName() << ": " << i.GetYear() << endl;
    }*/

    // SFML not working
    /*sf::RenderWindow window(sf::VideoMode(640, 480), "Project 3", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;


    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                break;
            default:
                break;
            }
        }

        window.clear();

        window.display();
    }*/

    bool running = true;

    int choice, search;
    string countryName, year;


    // Print to console for user
    while (running)
    {
        PromptChoices();
        cin >> choice;

        // Hashtable
        if (choice == 1)
        {
            SmokingHashMap hashTable(v);
            PromptSearches();
            cin >> search;
            switch (search)
            {
                case 1:
                    AskName();
                    cin >> countryName;
                    cout << endl;
                    AskYear();
                    cin >> year;

                    hashTable.Search(countryName, stoi(year));
                    break;
                case 2:

                    break;
                case 3:

                default:
                    break;
            }
        }
            // Graph (Adjaceny List)
        else if (choice == 2)
        {

        }
        else
        {
            cout << "INVALID INPUT! Pick 1 or 2.";
        }


    }

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

void PromptChoices()
{
    cout << "#1 Hashtable" << endl;
    cout << "#2 AdjacencyList" << endl;
    cout << "Select which data structure to use (Type 1 or 2): ";
}

void PromptSearches()
{
    cout << "#1 Search country and year" << endl;
    cout << "#2 Find country with greatest number of smokers" << endl;
    cout << "#3 Find country with largest percentage of smokers" << endl;
    cout << "#4 Find country with fewest number of smokers" << endl;
    cout << "#5 Find country with smallest percentage of smokers" << endl;
}

void AskName()
{
    cout << "Type in country name: ";
}

void AskYear()
{
    cout << "Type in year: ";
}