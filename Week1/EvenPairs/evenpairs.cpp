#include <iostream>
#include <vector>

/* DEBUG */
void printVector(const std::vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void readInput(std::vector<int>& bits)
{
    int n; std::cin >> n; // number of bits
    
    for (int i = 0; i < n; i++)
    {
        int x; std::cin >> x;
        bits.push_back(x);
    }
}

int bruteForce(const std::vector<int>& bits)
{
    int evenPairs = 0;

    for (int i = 0; i < (int)bits.size(); i++)
    {
        for (int j = i; j < (int)bits.size(); j++)
        {
            // DEBUG
            //std::cout << "i=" << i << " j=" << j << " "; 
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                // DEBUG
                //std::cout << bits.at(k) << " ";
                sum += bits.at(k);
            }

            if (sum % 2 == 0)
            {
                evenPairs++;
                // DEBUG
                //std::cout << "EVEN" << std::endl;
            }
            // DEBUG
            //else
            //{
                //std::cout << "ODD" << std::endl;
            //}
        }
    }

    return evenPairs;
}

void solveTest()
{
    std::vector<int> bits;
    readInput(bits);
    //printVector(bits);
    std::cout << bruteForce(bits) << std::endl;
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