#include <map>
#include <utility>
#include <vector>

namespace Graphs {

//------------------------------------------------------------------------------

using Weight = unsigned;
using NodeCosts = std::map<char, Weight>;

//------------------------------------------------------------------------------

struct Edge
{
  char u;
  char v;
  unsigned weight;
};

//------------------------------------------------------------------------------

class Graph
{
public:
  using AdjacentNodes = std::vector<std::pair<char, Weight>>;
  using AdjacencyList = std::map<char, AdjacentNodes>;

  Graph(std::vector<Edge>&& edges);

  const AdjacentNodes* const neighbours(char node) const;
  void shortestPath(char source, char dest, const std::map<char, Weight>& nodeCosts);
  void greedy(char source, char dest, const std::map<char, Weight>& nodeCosts);

private:
  AdjacencyList m_edges;
};

//------------------------------------------------------------------------------

}
