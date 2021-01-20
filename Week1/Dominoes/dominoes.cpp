#include <iostream>
#include <vector>

void readInput(std::vector<int>& dominoes)
{
    dominoes.clear();
    int n; std::cin >> n; // number of dominoes
    for(int i = 0; i < n; i++)
    {
        int h; std::cin >> h; // height of domino
        dominoes.push_back(h);
    }
}

int countFallen(const std::vector<int>& dominoes)
{
    int numFallen = 0;
    std::vector<bool> fallen(dominoes.size(), false);
    fallen.at(0) = true;

    for (size_t i = 0; i < dominoes.size(); i++)
    {
        if (fallen.at(i))
        {
            for (size_t j = i + 1; j < dominoes.size(); j++)
            {
                if ((int)j - (int)i < dominoes.at(i))
                {
                    fallen.at(j) = true;
                }
            }
        }
    }

    for (std::vector<bool>::iterator it = fallen.begin(); it != fallen.end(); it++)
    {
        if (*it)
            numFallen++;
    }
    return numFallen;
}

void solveTest()
{
    std::vector<int> dominoes;
    readInput(dominoes);
    std::cout << countFallen(dominoes) << std::endl;
}

int main()
{
    int t; std::cin >> t; // number of test cases

    for (int i = 0; i < t; i++)
        solveTest();
}