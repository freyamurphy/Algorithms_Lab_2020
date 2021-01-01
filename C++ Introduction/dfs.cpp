#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

typedef std::vector<std::pair<int, int>> IntPairVector;

void printVector(const std::vector<int> v)
{
  for (auto it = v.begin(); it != v.end(); it++)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void readInput(int &n, int &m, int &v, IntPairVector &edges)
{
  std::cin >> n >> m >> v;
  
  for (int i = 0; i < m; i++)
  {
    int a, b = 0;
    std::cin >> a >> b;
    edges.push_back(std::make_pair(a, b));
  }
}

void push(int &timestamp, const int value, std::stack<int> &vertices,
  std::vector<int> &discovery)
{
  vertices.push(value);
  discovery.at(value) = timestamp;
  timestamp++;
}

void pop(int &timestamp, std::stack<int> &vertices,
  std::vector<int> &finishing)
{
  int value = vertices.top();
  vertices.pop();
  finishing.at(value) = timestamp;
  timestamp++;
}

void getAdjacentVertices(const int vertex, const IntPairVector edges, 
  std::vector<int> &adjacentVertices)
{
  for (auto it = edges.begin(); it != edges.end(); it++)
  {
    if (it->first == vertex)
    {
      adjacentVertices.push_back(it->second);
    }
    else if (it->second == vertex)
    {
      adjacentVertices.push_back(it->first);
    }
  }
}

void dfs(const int initialVertex, const IntPairVector edges, 
  std::vector<int> &discovery, std::vector<int> &finishing)
{
  std::stack<int> vertices;
  int timestamp = 0;
  
  push(timestamp, initialVertex, vertices, discovery);
  
  while (!vertices.empty())
  {
    std::vector<int> adjacentVertices;
    getAdjacentVertices(vertices.top(), edges, adjacentVertices);
    std::sort(adjacentVertices.begin(), adjacentVertices.end());
    
    bool finished = true;
    for (auto it = adjacentVertices.begin(); it != adjacentVertices.end();
      it++)
    {
      if (discovery.at(*it) == -1)
      {
        push(timestamp, *it, vertices, discovery);
        finished = false;
        break;
      }
    }
    
    if (finished)
    {
      pop(timestamp, vertices, finishing);
    }
  }
}

void solveTest()
{
  // n = number of vertices
  // m = number of edges
  // v = starting vertex
  int n, m, v = 0;
  IntPairVector edges;
  readInput(n, m, v, edges);

  std::vector<int> discovery(n, -1);
  std::vector<int> finishing(n, -1);
  dfs(v, edges, discovery, finishing);
  
  printVector(discovery);
  printVector(finishing);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t = 0; std::cin >> t;   // number of tests
    
    for (int i = 0; i < t; i++)
    {
      solveTest();
    }
}