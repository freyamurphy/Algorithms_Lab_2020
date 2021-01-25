#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void printVector(std::vector<int>* vector)
{
  for (std::vector<int>::iterator it = vector->begin(); it != vector->end();
       it++)
  {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

void readCoins(std::vector<int>* coins)
{
  int value = 0;
  for (std::vector<int>::iterator it = coins->begin(); it != coins->end(); it++)
  {
    std::cin >> value;
    *it = value;
  }
}

int guaranteedWinnings(std::vector<int>* coins, bool myTurn, 
                       std::map<std::vector<int>, int>* memoMyTurn, 
                       std::map<std::vector<int>, int>* memoTheirTurn)
{
  if (myTurn)
  {
    if (coins->size() == 1)
    {
      return coins->at(0);
    }

    if (memoMyTurn->find(*coins) == memoMyTurn->end())
    {
      std::vector<int> splitAtStart(coins->begin() + 1, coins->end());
      std::vector<int> splitAtEnd(coins->begin(), coins->end() - 1);
      int choice1 = coins->at(0) + guaranteedWinnings(&splitAtStart, !myTurn,
        memoMyTurn, memoTheirTurn);
      int choice2 = guaranteedWinnings(&splitAtEnd, !myTurn, memoMyTurn,
        memoTheirTurn) + coins->back();
      int winnings = std::max(choice1, choice2);
      memoMyTurn->insert(make_pair(*coins, winnings));
    }
    
    return memoMyTurn->at(*coins);
  }
  else
  {
    if (coins->size() == 1)
    {
      return 0;
    }
    
    if (memoTheirTurn->find(*coins) == memoTheirTurn->end())
    {
      std::vector<int> splitAtStart(coins->begin() + 1, coins->end());
      std::vector<int> splitAtEnd(coins->begin(), coins->end() - 1);
      int choice1 = guaranteedWinnings(&splitAtStart, !myTurn, memoMyTurn, 
        memoTheirTurn);
      int choice2 = guaranteedWinnings(&splitAtEnd, !myTurn, memoMyTurn, 
        memoTheirTurn);
      int winnings = std::min(choice1, choice2); 
      // Opponent with choose option that minimises my winnings
      memoTheirTurn->insert(make_pair(*coins, winnings));
    }
    return memoTheirTurn->at(*coins);
  }
}

void solveTest(std::map<std::vector<int>, int>* memoMyTurn,
               std::map<std::vector<int>, int>* memoTheirTurn)
{
  int n = 0;
  std::cin >> n;
  
  std::vector<int> coins(n);
  readCoins(&coins);
  
  std::cout << guaranteedWinnings(&coins, true, memoMyTurn, memoTheirTurn);
  std::cout << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  std::map<std::vector<int>, int> memoMyTurn;
  std::map<std::vector<int>, int> memoTheirTurn;
  
  int t = 0;
  std::cin >> t;
  for (int i = 0; i < t; i++)
  {
    solveTest(&memoMyTurn, &memoTheirTurn);
  }
}