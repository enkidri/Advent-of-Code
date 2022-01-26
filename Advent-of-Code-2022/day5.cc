#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <fstream>
using namespace std;

class Grid
{
    public:
        Grid()
        {}

        int printSize()
        {
            return gridSize;
        }

        void printGrid()
        {
            for (auto const& r:grid)
            {
                for (auto number:r)
                {
                    if (number == 0)
                    {
                        cout << " . ";
                        continue;
                    }
                    cout << " " << number << " ";
                }
                cout << endl;
            }
        }

        void addLine(string input)
        {
            const regex r("([\\d]+),([\\d]+) -> ([\\d]+),([\\d]+)");
            smatch sm;
            vector<int> coord{};
            int prevSize{gridSize};

            if (regex_search(input, sm, r))
            {
                for (int i=1; i < sm.size(); ++i)
                {
                    int currNr = stoi(sm[i]);
                    if (currNr > gridSize)
                    {
                        gridSize = currNr + 1;  //+1 to include orgin
                    }
                    coord.push_back(stoi(sm[i]));
                }
            }
            int to_resize = gridSize - prevSize;

            if (to_resize > 0)
            {
                this -> modifyGrid(to_resize);
            }

            if (coord[0] == coord[2])
            {
                int isDown = coord[1] - coord[3];
                if (isDown > 0)
                {
                    for (int i=coord[1]; i >= coord[3]; --i)
                    {
                        grid[i][coord[0]] += 1;
                    }
                }
                else
                {
                    for (int i=coord[1]; i <= coord[3]; ++i)
                    {
                        grid[i][coord[0]] += 1;
                    }
                }
            }
            else if(coord[1] == coord[3])
            {
                int isDown = coord[0] - coord[2];
                if (isDown > 0)
                {
                    for (int i=coord[0]; i >= coord[2]; --i)
                    {
                        grid[coord[1]][i] += 1;
                    }
                }
                else
                {
                    for (int i=coord[0]; i <= coord[2]; ++i)
                    {
                        grid[coord[1]][i] += 1;
                    }
                }
            }

        }

        void printDanger() const
        {
            int dangerPoints{};
            for (auto const& r:grid)
            {
                for (auto const& nr:r)
                {
                    if (nr >= 2)
                    {
                        ++dangerPoints;
                    }
                }
            }

            cout << "There are " << dangerPoints << " numbers of dangerous points." << endl;
        }

    private:
        void modifyGrid(int inc)
        {
            grid.resize(gridSize);
            for (auto& r:grid)
            {
                r.resize(gridSize);
            }
        }

        vector<int> row;
        vector<vector<int>> grid;
        int gridSize{};

};

void partOne()
{
    Grid grid{};
    ifstream f{"day5.txt"};
    string line;
    while (getline(f, line))
    {
        grid.addLine(line);
    }
    grid.printDanger();
}

int main()
{
    partOne();
    return 0;
}