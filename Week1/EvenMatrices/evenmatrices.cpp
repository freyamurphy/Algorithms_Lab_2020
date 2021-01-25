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

/* Code from solution handout */
void precomputeSums(std::vector<std::vector<int> >& sums, const std::vector<std::vector<int> >& matrix)
{
    // Compute sums[i][j] by using the values sums[i'][j'] for 
    // i' <= i and j' <= j.
    for (size_t i = 1; i < sums.size(); ++i)
    {
        for (size_t j = 1; j < sums.size(); ++j)
        {
            sums.at(i).at(j) = sums.at(i - 1).at(j) + sums.at(i).at(j - 1) - sums.at(i - 1).at(j - 1) + matrix.at(i-1).at(j-1);
        }
    }
}

int countEvenPairs(const std::vector<std::vector<int> >& matrix)
{
    int evenPairs = 0;

    // Precompute sums
    std::vector<std::vector<int> > sums;
    for (size_t i = 0; i < matrix.size()+1; i++)
    {
        std::vector<int> row;
        for (size_t j = 0; j < matrix.size()+1; j++)
        {
            row.push_back(0);
        }
        sums.push_back(row);
    }
    precomputeSums(sums, matrix);

    // Go through all possible quadruples
    for (size_t i1 = 1; i1 < sums.size(); i1++)
    {
        for (size_t i2 = i1; i2 < sums.size(); i2++)
        {
            for (size_t j1 = 1; j1 < sums.size(); j1++)
            {
                for (size_t j2 = j1; j2 < sums.size(); j2++)
                {
                    // Formula from solution handout
                    int sum = sums.at(i2).at(j2) - sums.at(i2).at(j1 - 1) - sums.at(i1 - 1).at(j2) + sums.at(i1 - 1).at(j1 - 1);

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