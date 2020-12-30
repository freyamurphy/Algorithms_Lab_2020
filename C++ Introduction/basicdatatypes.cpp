#include <iostream>
#include <string>

void solveTest()
{
  int val1 = 0;
  long val2 = 0L;
  std::string val3 = "";
  double val4 = 0.0;
  
  std::cin >> val1;
  std::cin >> val2;
  std::cin >> val3;
  std::cin >> val4;
  
  std::cout << val1 << " "
            << val2 << " "
            << val3 << " "
            << val4 << " ";
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  int numTestCases = 0; std::cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++)
  {
    solveTest();
  }
}