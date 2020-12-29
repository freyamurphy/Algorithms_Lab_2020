#include <iostream>

using namespace std;

void solveTestCase()
{
  int numValues = 0;
  cin >> numValues;
  
  int total = 0;
  for (int i = 0; i < numValues; i++)
  {
    int val = 0;
    cin >> val;
    total += val;
  }
  
  cout << total << endl;
}

int main()
{
  int numTestCases = 0;
  cin >> numTestCases;
  
  for (int i = 0; i < numTestCases; i++)
  {
    solveTestCase();
  }
}