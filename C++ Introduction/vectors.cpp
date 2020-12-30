#include <iostream>
#include <vector>

void solveTest()
{
  int n = 0;
  std::cin >> n;
  
  std::vector<int> v(n);
  int val;
  for (int i = 0; i < n; i++)
  {
    std::cin >> val;
    v.at(i) = val;
  }
  
  int elementToDelete = 0;
  std::cin >> elementToDelete;
  std::vector<int> v2;
  for (int i = 0; i < n; i++)
  {
    if (i != elementToDelete)
    {
      v2.push_back(v.at(i));
    }
  }
  
  int startRange = 0;
  int endRange = 0;
  std::cin >> startRange;
  std::cin >> endRange;
  std::vector<int> v3;
  for (int i = 0; i < n-1; i++)
  {
    if (!(i >= startRange && i <= endRange))
    {
      v3.push_back(v2.at(i));
    }
  }
  
  if (v3.size() == 0)
  {
    std::cout << "Empty" << "\n";
  }
  else
  {
    for (int i : v3)
    {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  int numTestCases = 0;
  std::cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++)
  {
    solveTest();
  }
  
}