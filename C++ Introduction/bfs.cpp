#include <iostream>
#include <queue>
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

void bfs(const int initialVertex, const IntPairVector edges, 
  std::vector<int> &distances)
{
  std::queue<int> vertices;
  
  vertices.push(initialVertex);
  distances.at(initialVertex) = 0;
  
  while (!vertices.empty())
  {
    int currentVertex = vertices.front();
    std::vector<int> neighbours;
    getAdjacentVertices(currentVertex, edges, neighbours);

    for (auto it = neighbours.begin(); it != neighbours.end(); it++)
    {
      if (distances.at(*it) == -1)
      {
        vertices.push(*it);
        distances.at(*it) = distances.at(currentVertex) + 1;
      }
    }

    vertices.pop();
  }
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

void solveTest()
{
  int n, m, v = 0;
  IntPairVector edges;
  readInput(n, m, v, edges);

  std::vector<int> distances(n, -1);
  bfs(v, edges, distances);
  
  printVector(distances);
}

int main() 
{
  std::ios_base::sync_with_stdio(false);
  
  int t = 0; std::cin >> t;   // number of tests
    
  for (int i = 0; i < t; i++)
  {
    solveTest();
  }
}