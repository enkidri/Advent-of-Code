#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream f{"day3_input.txt",};
    string line{};
    int total_lines{};
    vector<double> rate_prob(12);
    int i{};

    vector<string> file{};
    if (f.is_open())
    {
        while(f >> line)
        {
            file.push_back(line);
            ++total_lines;
        }
    }

    int y{};
    for (int i=0; i < file.size(); ++i)
    {
        line = file[i];
        y = 0;
        for (char const& c:line)
        {
            if (c == '1')
            {
                rate_prob.at(y) += 1.0;
            }
            ++y;
        }
    }

    transform(rate_prob.begin(), rate_prob.end(), rate_prob.begin(),
            [&total_lines](double &c)
            {
                return c/total_lines;
            });

    string gamma{};
    string epsilon{};
    for (auto prob:rate_prob)
    {
        cout << prob << endl;
        if (prob>0.5)
        {
            gamma += '1';
            epsilon += '0';
        }
        else
        {
            gamma += '0';
            epsilon += '1';
        }
    }

    cout << "Gamma: " << gamma << "\n" <<
            "Epsilon: " << epsilon << endl;

    return 0;
}