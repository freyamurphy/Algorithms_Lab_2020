#include <iostream>
#include <vector>
#include <cmath>

/*
void printVector(std::vector<int>* v)
{
  for (std::vector<int>::iterator it = v->begin(); it != v->end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}
*/

void readCardValues(std::vector<int>* cardValues)
{
  int v = 0;
  for (int i = 0; i < (int)cardValues->size(); i++)
  {
    std::cin >> v;
    cardValues->at(i) = v;
  }
}

void calculatePartialSums(std::vector<int>* cardValues, std::vector<int>* sums)
{
  int sum = 0;
  for (int i = 0; i < (int)sums->size(); i++)
  {
    sum += cardValues->at(i);
    sums->at(i) = sum;
  }
}

std::pair<int, int> findPair(std::vector<int>* cardValues, int targetSum)
{
  int closestI = -1;
  int closestJ = -1;
  int closestSumDiff = targetSum;
  
  std::vector<int> partialSums(cardValues->size());
  calculatePartialSums(cardValues, &partialSums);
  
  for (int i = 0; i < (int)cardValues->size(); i++)
  {
    for (int j = 0; j < (int)cardValues->size(); j++)
    {
      int sum = 0;
      
      if (i == 0)
      {
        sum = partialSums.at(j);
      }
      else
      {
        sum = partialSums.at(j) - partialSums.at(i-1);
      }
      
      if (sum == targetSum)
      {
        return std::make_pair(i, j);
      }
      else if (std::abs(targetSum - sum) < closestSumDiff)
      {
        closestI = i;
        closestJ = j;
        closestSumDiff = std::abs(targetSum - sum);
      }
      
      if (sum > targetSum)
        break;
    }
  }
  
  return std::make_pair(closestI, closestJ);
}

void solveTest()
{
  int n = 0;
  int k = 0;
  std::cin >> n;
  std::cin >> k;
  
  std::vector<int> cardValues(n);
  readCardValues(&cardValues);
  
  std::pair<int, int> solution = findPair(&cardValues, k);
  std::cout << solution.first << " " << solution.second << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++)
  {
    solveTest();
  }
}