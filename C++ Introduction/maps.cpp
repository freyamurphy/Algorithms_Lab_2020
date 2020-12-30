#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

void printMap(std::multimap<std::string, int>* m)
{
  //std::cout << "printing map" << std::endl;
  if (m->size() == 0)
  {
    std::cout << "Empty";
  }
  else {
    std::multimap<std::string, int>::iterator it = m->begin();
    while (it != m->end())
    {
      std::cout << "(" << it->first << ", " << it->second << ") ";
      it++;
    }
  }
  std::cout << std::endl;
}

void processLine(std::multimap<std::string, int>* m)
{
  int a = 0;
  std::string b = "";
  std::cin >> a;
  std::cin >> b;
  
  if (a == 0)
  {
    // erase all entries with b as the key
    std::multimap<std::string, int>::iterator it = m->find(b);
    while (it != m->end())
    {
      //std::cout << "removing (" << b << ", " /*<< m->at(b) */<< ")" << std::endl;
      m->erase(it);
      it = m->find(b);
    }
  }
  else
  {
    // add key b value a
    //std::cout << "inserting (" << b << ", " << a << ")" << std::endl;
    m->insert(std::make_pair(b, a));
  }
  
  //printMap(m);
}

void solveTest()
{
  int q = 0;
  std::cin >> q;
  
  std::multimap<std::string, int> m = std::multimap<std::string, int>();
  
  for (int i = 0; i < q; i++)
  {
    processLine(&m);
  }
  
  std::string s = "";
  std::cin >> s;
  
  std::multimap<std::string, int>::iterator it = m.find(s);
  if (it == m.end())
  {
    std::cout << "Empty";
  }
  
  std::vector<int> values;
  while (it != m.end())
  {
    //std::cout << "Found (" << it->first << ", " << it->second << ")" << std::endl;
    values.push_back(it->second);
    m.erase(it);
    it = m.find(s);
  }
  
  std::sort(values.begin(), values.end());
  for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
  {
    std::cout << *it << " ";
  }
  
  std::cout << "\n";
  
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