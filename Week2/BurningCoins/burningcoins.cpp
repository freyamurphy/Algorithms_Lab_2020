#include <iostream>
#include <vector>

void readCoins(std::vector<int>& coins, int n)
{
  for (int i = 0; i < n; i++)
  {
    int v; std::cin >> v; // value of coin
    coins.push_back(v);
  }
}

int guaranteedWinnings(const std::vector<int>& coins, std::vector<std::vector<int> >& memo, int left, 
  int right, bool myTurn)
{
  if (left == right)
  {
    if (myTurn)
      return coins.at(left);
    else
      return 0;
  }

  if (memo.at(left).at(right) == -1)
  {
    int chooseLeft = coins.at(left) + guaranteedWinnings(coins, memo, left + 1, right, !myTurn);
    int chooseRight = coins.at(right) + guaranteedWinnings(coins, memo, left, right - 1, !myTurn);

    int winnings = 0;
    if (myTurn)
      winnings = std::max(chooseLeft, chooseRight);
    else
      winnings = std::min(chooseLeft - coins.at(left), chooseRight - coins.at(right));

    memo.at(left).at(right) = winnings;
  }
  
  return memo.at(left).at(right);
}

void initialiseMemo(std::vector<std::vector<int> >& memo, int n)
{
  for (int i = 0; i < n; i++)
  {
    std::vector<int> row(n, -1);
    memo.push_back(row);
  }
}

void solveTest()
{
  int n; std::cin >> n; // number of coins
  std::vector<int> coins;
  readCoins(coins, n);
  std::vector<std::vector<int> > memo;
  initialiseMemo(memo, n);
  std::cout << guaranteedWinnings(coins, memo, 0, coins.size()-1, true) << std::endl;
}

int main()
{
  std::ios_base::sync_with_stdio(false);

  int t; std::cin >> t; // number of test cases
  for (int i = 0; i < t; i++)
  {
    solveTest();
  }

  return 0;
}