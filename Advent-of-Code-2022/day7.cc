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

    int n = pos.size();
    int median{};
    if (n % 2 == 0)
    {
        nth_element(pos.begin(), pos.begin() + n/2, pos.end());
        int a = pos[n/2];
        nth_element(pos.begin(), pos.begin() + (n-1)/2, pos.end());
        int b = pos[(n-1)/2];
        median = (a + b) / 2;
    }
    else
    {
        nth_element(pos.begin(), pos.begin() + n/2, pos.end());
        median = pos[n / 2];
    }

    cout << median << endl;

    int cost{};
    for (auto const& p:pos)
    {
        cost += abs(p-median);
    }

    cout << "The total cost is " << cost << endl;



    return 0;
}