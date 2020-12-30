#include <iostream>
#include <set>

void performSetOperation(std::set<int>* s)
{
  int a = 0;
  int b = 0;
  std::cin >> a;
  std::cin >> b;
  
  if (a == 0)
  {
    s->insert(b);
  }
  else
  {
    std::set<int>::iterator it = s->find(b);
    if (it != s->end())
    {
      s->erase(it);
    }
  }
}

void outputSet(std::set<int>* s)
{
  if (s->size() == 0)
  {
    std::cout << "Empty";
  }
  else
  {
    for (int i : *s)
    {
      std::cout << i << " ";
    }
  }
  std::cout << "\n";
}

void solveTest()
{
  int q = 0;
  std::cin >> q;
  
  std::set<int> s = std::set<int>();
  
  for (int i = 0; i < q; i++)
  {
    performSetOperation(&s);
  }
  outputSet(&s);
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