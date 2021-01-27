#include <iostream>
#include <vector>
#include <map>

std::string encodeStateString(int redPosition, int blackPosition, bool moriartysTurn,
  bool holmesTurnsEven, bool moriartyTurnsEven)
{
  std::string state = "";
  state += std::to_string(redPosition);
  state += " ";
  state += std::to_string(blackPosition);
  state += " ";
  
  if (moriartysTurn)
    state += "1";
  else
    state += "0";
    
  if (holmesTurnsEven)
    state += "1";
  else
    state += "0";
    
  if (moriartyTurnsEven)
    state += "1";
  else
    state += "0";
  
  return state;
}

void printTransitions(const std::vector<std::pair<int, int>>& transitions)
{
  for (auto it = transitions.begin(); it != transitions.end(); it++)
  {
    std::cout << it->first << " " << it->second << std::endl;
  }
}

void readTransitions(std::vector<std::pair<int, int>>& transitions)
{
  for (auto it = transitions.begin(); it != transitions.end(); it++)
  {
    int transitionStart = 0;  // u
    std::cin >> transitionStart;
    
    int transitionEnd = 0;  // v
    std::cin >> transitionEnd;
    
    *it = std::make_pair(transitionStart, transitionEnd);
  }
}

bool doesMoriartyWin(int redPosition, int blackPosition, bool moriartysTurn,
  bool holmesTurnsEven, bool moriartyTurnsEven, 
  const std::vector<std::pair<int, int>>& transitions, int target, 
  std::map<std::string, bool> memo)
{
  std::string state = encodeStateString(redPosition, blackPosition, 
    moriartysTurn, holmesTurnsEven, moriartyTurnsEven);
  
  /* First, lets see if this is a winning state. */
  if (redPosition == target)
  {
    memo.insert(std::make_pair(state, false));
    return false;
  }
  else if (blackPosition == target)
  {
    memo.insert(std::make_pair(state, true));
    return true;
  }
  
  /* Let's calculate which meeple will be moving. */
  bool redToMove = false;
  if (moriartysTurn && !moriartyTurnsEven)
    redToMove = true;
  else if (!moriartysTurn && holmesTurnsEven)
    redToMove = true;
    
  /* Now, let's calculate all of the potential transitions. */
  std::vector<int> potentialDestinations;
  for (auto it = transitions.begin(); it != transitions.end(); it++)
  {
    if (redToMove && it->first == redPosition)
      potentialDestinations.push_back(it->second);
    else if (!redToMove && it->first == blackPosition)
      potentialDestinations.push_back(it->second);
  }
  
  /* Now, for each potential move, we want to see if Moriarty will win. */
  for (auto it = potentialDestinations.begin(); 
    it != potentialDestinations.end(); it++)
  {
    int newRedPosition = redPosition;
    if (redToMove)
      newRedPosition = *it;
      
    int newBlackPosition = blackPosition;
    if (!redToMove)
      newBlackPosition = *it;
      
    int newHolmesTurnsEven = holmesTurnsEven;
    if (!moriartysTurn)
      newHolmesTurnsEven = !holmesTurnsEven;
      
    int newMoriartyTurnsEven = moriartyTurnsEven;
    if (moriartysTurn)
      newMoriartyTurnsEven = !moriartyTurnsEven;
      
    /* Check whether the result in the memo 
     * Unfortunately I still get time limit exceeded.
     */
    std::string newState = encodeStateString(newRedPosition, newBlackPosition,
      !moriartysTurn, newHolmesTurnsEven, newMoriartyTurnsEven);
      
    bool moriartyWins = false;
    auto mapIt = memo.find(newState);
    if (mapIt != memo.end())
      moriartyWins = mapIt->second;
    else
      moriartyWins = doesMoriartyWin(newRedPosition, newBlackPosition, 
      !moriartysTurn, newHolmesTurnsEven, newMoriartyTurnsEven, transitions, 
      target, memo);
      
    /* If it is Moriarty's turn, and there is 1 possible move which lets him
     * win, choose that move.
     * If it si Holmes' turn, and there is 1 possible move which makes Moriarty
     * lose, choose that move.
     * As soon as we find a desirable outcome we can stop checking the rest.
     */
    if (moriartysTurn && moriartyWins)
    {
      memo.insert(std::make_pair(state, true));
      return true;
    }
    else if (!moriartysTurn && !moriartyWins)
    {
      memo.insert(std::make_pair(state, false));
      return false;
    }
  }
  
  /* If it is Moriarty's turn, we have tried every possible move and found no
   * possibility of winning. Therefore, Moriarty cannot win.
   * If it is Holmes' turn, we have tried every possible move and found no
   * possiblity of Moriarty losing. Therefore, Moriarty must win.
   */
  if (moriartysTurn)
  {
    memo.insert(make_pair(state, false));
    return false;
  }
  else
  {
    memo.insert(make_pair(state, false));
    return true;
  }
}

void solveTest() {
  int numPositions = 0; // n
  std::cin >> numPositions;
  
  int numTransitions = 0; // m
  std::cin >> numTransitions;
  
  int redStart = 0; // r
  std::cin >> redStart;
  
  int blackStart = 0; // b
  std::cin >> blackStart;
  
  std::vector<std::pair<int, int>> transitions(numTransitions);
  readTransitions(transitions);
  
  // The memo will map a string (state) to a bool (result)
  std::map<std::string, bool> memo;
  
  bool moriartyWins = doesMoriartyWin(redStart, blackStart, false, true, true,
    transitions, numPositions, memo);
  if (moriartyWins)
    std::cout << "1" << std::endl;
  else
    std::cout << "0" << std::endl;
  //printTransitions(transitions);
  
  /* Freya thoughts:
   * The state of a game (given the nodes and transitions) is defined by the
   * positions of the meeple, whose turn it is, the number of turns taken by
   * Holmes, and the number of turns taken by Moriarty:
   *    G(rPos, bPos, player, hTurns, mTurns) = 
   *      G(rPos', bPos', !player, hTurns', mTurns') + make a turn
   * Given the current state, we can update that state for each potential
   * move (i.e. all of the transitions coming from the current position).
   * Then, we can calculate whether Holmes would win each of the potential new
   * game states.
   * Finally, we can choose whichever move results in him winning.
   * Normally I would choose the 'best' move but here a move is either winning,
   * or losing. So we could end the computation as soon as we find 1 winning
   * move.
   * And of course we can use dymanic programming to store the results of
   * previous computations.
   *
   * Problem: The game state cannot be described by just a single integer. This
   * means dynamic programming will be less efficient. I could probably
   * convert the state into a string and then map that to a result.
   *
   * First of all I will write the recursive function to solve the problem,
   * and if that works I will try to add dynamic programming.
   *
   * Good news, my basic non-dynamic programming solution passed test sets
   * 1 and 2!
   *
   * Next I will need to implement dynamic programming to make it faster.
   * This requires saving a record of the result for each game state.
   * Since the state is defined by multiple variables, I will concatenate them
   * into a string and use that in a hash map.
   * It is best to use a single integer so that I can use a vector instead of
   * a map, but I cannot see how the state could be represented by an integer
   * in this case, unless I just used the binary of the string? That seems
   * like the vector would end up being far too big.
   */
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  
  int numTestCases = 0; // t
  std::cin >> numTestCases;
  
  for (int i = 0; i < numTestCases; i++)
  {
    solveTest();
  }
}