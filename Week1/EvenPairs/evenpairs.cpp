#include <iostream>
#include <vector>

void readInput(std::vector<int>& bits)
{
    int n; std::cin >> n; // number of bits
    
    for (int i = 0; i < n; i++)
    {
        int x; std::cin >> x;
        bits.push_back(x);
    }
}

int partialSums(const std::vector<int>& bits)
{
    int evenPairs = 0;

    std::vector<int> partialSums;
    int sum = 0;
    for (std::vector<int>::const_iterator it = bits.begin(); it != bits.end(); it++)
    {
        sum += *it;
        partialSums.push_back(sum);
    }

    for (size_t i = 0; i < bits.size(); i++)
    {        
        for (size_t j = i; j < bits.size(); j++)
        {
            int sum = 0;
            if (i == 0) 
                sum = partialSums.at(j);
            else
                sum = partialSums.at(j) - partialSums.at(i-1);

            if (sum % 2 == 0) evenPairs++;
        }        
    }

    return evenPairs;
}

void solveTest()
{
    std::vector<int> bits;
    readInput(bits);
    std::cout << partialSums(bits) << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t; std::cin >> t;   // number of test cases
    for (int i = 0; i < t; i++)
    {
        solveTest();
    }
}