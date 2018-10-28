#include "Graph.h"

namespace Graphs {

//------------------------------------------------------------------------------

Graph::Graph(std::vector<Edge>&& edges)
{
  for (const auto& e : edges)
  {
    if (m_edges.count(e.u) == 0)
      m_edges[e.u] = AdjacentNodes();

    m_edges[e.u].emplace_back(e.v, e.weight);
  }
}

//------------------------------------------------------------------------------

const Graph::AdjacentNodes* const Graph::neighbours(char node) const
{
  return m_edges.find(node) != m_edges.end() ? &m_edges.at(node) : nullptr;
}

//------------------------------------------------------------------------------

void Graph::shortestPath(char source, char dest,
                         const std::map<char, Weight>& nodeCosts)
{
  //TODO: implement me - print the shortest path using Dijkstra/A*
}

//------------------------------------------------------------------------------

}
