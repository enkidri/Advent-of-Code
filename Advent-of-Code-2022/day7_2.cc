#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <numeric>
#include <math.h>
#include <sstream>
#include <algorithm>
using namespace std;


int main(int argv, char** argc)
{
    vector<int> pos;
    ifstream f{argc[1]};
    string line{};
    while(getline(f,line))
    {
        stringstream ss(line);
        for (int i; ss >> i;)
        {
            pos.push_back(i);
            if (ss.peek() == ',')
            {
                ss.ignore();
            }
        }
    }

    int max = *max_element(pos.begin(), pos.end());

    int cost{};
    vector<int> costs;
    int average = 0;
    for (int i=0; i < max; ++i)         //Brute fucking force motherfucker
    {
        cost = 0;
        for (auto const& p:pos)
        {
            int dist = abs(p-average);
            cost += dist*(1 + dist) / 2;
        }
        costs.push_back(cost);
        ++average;
    }

    cout << "The minimal cost is " << *min_element(costs.begin(), costs.end()) << endl;

    return 0;
} 