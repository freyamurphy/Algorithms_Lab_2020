#include <iostream>
#include <vector>

void readMatrix(std::vector<std::vector<int> >& matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < n; j++)
        {
            int x; std::cin >> x; // matrix entry
            row.push_back(x);
        }
        matrix.push_back(row);
    }
}

int countEvenPairs(const std::vector<std::vector<int> >& matrix)
{
    int evenPairs = 0;

    // Go through all possible quadruples
    for (size_t i1 = 0; i1 < matrix.size(); i1++)
    {
        for (size_t i2 = i1; i2 < matrix.size(); i2++)
        {
            for (size_t j1 = 0; j1 < matrix.size(); j1++)
            {
                for (size_t j2 = j1; j2 < matrix.size(); j2++)
                {
                    // Add up everything in this range
                    int sum = 0;
                    for (size_t k = i1; k <= i2; k++)
                    {
                        for (size_t l = j1; l <= j2; l++)
                        {
                            sum += matrix.at(k).at(l);
                        }
                    }

                    if (sum % 2 == 0)
                    {
                        evenPairs++;
                    }
                }
            }
        }
    }

    return evenPairs;
}

void solveTest()
{
    int n; std::cin >> n; // dimension of matrix
    std::vector<std::vector<int> > matrix;
    readMatrix(matrix, n);
    std::cout << countEvenPairs(matrix) << std::endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t; std::cin >> t; // number of test cases
    for (int i = 0; i < t; i++)
    {
        solveTest();
    }

    return 0;

}