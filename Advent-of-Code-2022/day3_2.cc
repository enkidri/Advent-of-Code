#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

string oxygen(vector<string> bins)
{
    int i{};
    double rate{};
    int line_size{};
    vector<string> temp{};
    while(bins.size() > 1)
    {
        rate = 0;
        line_size = 0;
        for (auto bin:bins)
        {
            if (bin[i] == '1')
            {
                rate += 1.0;
            }
            ++line_size;
        }
        for (auto bin:bins)
        {
            if (bin[i] == '1' && (rate/line_size >= 0.5))
            {
                temp.push_back(bin);
            }
            else if(bin[i] == '0' && (rate/line_size < 0.5))
            {
                temp.push_back(bin);
            }
        }
        ++i;
        bins = temp;
        temp.clear();
    }
    return bins[0];
}

string CO_2(vector<string> bins)
{
    int i{};
    double rate{};
    int line_size{};
    vector<string> temp{};
    while(bins.size() > 1)
    {
        rate = 0;
        line_size = 0;
        for (auto bin:bins)
        {
            if (bin[i] == '1')
            {
                rate += 1.0;
            }
            ++line_size;
        }
        for (auto bin:bins)
        {
            if (bin[i] == '1' && (rate/line_size < 0.5))
            {
                temp.push_back(bin);
            }
            else if(bin[i] == '0' && (rate/line_size >= 0.5))
            {
                temp.push_back(bin);
            }
        }
        ++i;
        bins = temp;
        temp.clear();
    }
    return bins[0];
}

int bin_to_dec(string const& str)
{
    string r_str = string(str.rbegin(), str.rend());
    int i{};
    int dec{};
    for (auto l:r_str)
    {
        if (l == '1')
        {
            dec += pow(2,i);
        }
        ++i;
    }
    return dec;
}

int main()
{
    ifstream f{"day3_input.txt"};
    string line;
    vector<string> bins{};
    
    while (f >> line)
    {
        bins.push_back(line);
    }

    string oxy{oxygen(bins)};
    string CO2{CO_2(bins)};

    cout << "Oxygen rating: " << oxy << "\n" <<
            "CO 2 rating: " << CO2 << endl;

    int prod{bin_to_dec(oxy) * bin_to_dec(CO2)};

    cout << "Solution: " << prod << endl;

    return 0;
}