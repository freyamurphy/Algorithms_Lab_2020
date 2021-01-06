#include <iostream>
#include <vector>
#include <algorithm>

void printVector(std::vector<int>* vector)
{
  for (std::vector<int>::iterator it = vector->begin(); it != vector->end();
       it++)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

void readNumbers(std::vector<int>* numbers)
{
  int value = 0;
  for (std::vector<int>::iterator it = numbers->begin(); it != numbers->end();
       it++)
  {
    std::cin >> value;
    *it = value;
  }
}

void solveTest()
{
  int n = 0;
  std::cin >> n;
  
  std::vector<int> numbers(n);
  readNumbers(&numbers);
  
  int sortDecreasing = 0;
  std::cin >> sortDecreasing;
  
  if (sortDecreasing)
  {
    sort(numbers.begin(), numbers.end(), std::greater<>());
  }
  else
  {
    sort(numbers.begin(), numbers.end());
  }
  printVector(&numbers);
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