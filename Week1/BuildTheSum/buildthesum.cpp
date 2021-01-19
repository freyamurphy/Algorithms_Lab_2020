#include <iostream>
#include <vector>

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

int sumValues(std::vector<int>* values)
{
  int sum = 0;
  for (std::vector<int>::iterator it = values->begin(); it != values->end();
       it++)
  {
    sum += *it;
  }
  return sum;
}

void solveTest()
{
  int n = 0;
  std::cin >> n;
  
  std::vector<int> numbers(n);
  readNumbers(&numbers);
  int sum = sumValues(&numbers);
  std::cout << sum << "\n";
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