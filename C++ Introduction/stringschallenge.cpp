#include <iostream>
#include <string>

void solveTest()
{
  std::string str1 = "";
  std::string str2 = "";
  
  std::cin >> str1;
  std::cin >> str2;
  
  std::cout << str1.length() << " " << str2.length() << "\n";
  std::cout << str1 + str2 << "\n";
  
  std::string revStr1 = "";
  for (int i = str1.length()-1; i >= 0; i--)
  {
    revStr1 += str1[i];
  }
  
  std::string revStr2 = "";
  for (int i = str2.length()-1; i >= 0; i--)
  {
    revStr2 += str2[i];
  }
  
  char temp = revStr1[0];
  revStr1[0] = revStr2[0];
  revStr2[0] = temp;
  
  std::cout << revStr1 << " " << revStr2 << "\n";
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