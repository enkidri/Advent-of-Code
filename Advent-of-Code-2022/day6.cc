#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

class School // (of fish)
{
    public:
        School()
        {}
        ~School()
        {
            for (auto& fish:school)
            {
                delete fish;
            }
        }

    void getInitial(string const& line)
    {
        for (auto const& digit:line)
        {
            if (!isdigit(digit))
            {
                continue;
            }
            school.push_back(new LanternFish{digit - '0'});
        }
    }

    void printFishes()
    {
        cout << "\t";
        for (auto const& fish:school)
        {
            cout<< (*fish).age << "," ;
        }
        cout << endl;
    }

    void increaseDay()
    {
        for (auto& fish:school) //Comment: school is too big, this type of loop doesnt work(?)
        {
            --(*fish).age;
            if ((*fish).age == -1)
            {
                (*fish).age = 6;
                school.push_back(new LanternFish{8});
            }
            // else
            // {
            //     (*fish).isNew = false;
            // }
        }
    }

    int schoolSize()
    {
        return school.size();
    }

    private:
        struct LanternFish
        {
            int age;
        };
        vector<LanternFish*> school;
};

void PartOne(string const& filename)
{
    ifstream f{filename};
    string line;
    School school;

    while(getline(f,line))
    {
        school.getInitial(line);
    }
    cout << "Initial state: ";
    school.printFishes();
    
    int days = 3;
    for (int i=1; i <= days; ++i)
    {
        school.increaseDay();
        cout << "After " << i << " days: ";
        school.printFishes();
    }

    cout << "The size of the school after " << days << " days is " << school.schoolSize();

}

int main(int argc, char* argv[])
{
    PartOne(argv[1]);

    return 0;
}