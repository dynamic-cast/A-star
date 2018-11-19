#include "Graph.h"
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

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

  void Graph::greedy(char source, char dest, const std::map<char, Weight>& nodeCosts)
  {
    std::vector<char> visited{source};
    auto current = source;
    while (current != dest)
    {
        // find smallest value in m_edges.at(current)
        Graph::AdjacentNodes adjacents = m_edges.at(current);
        auto minimum = std::min_element(adjacents.begin(), adjacents.end(),
            [&nodeCosts](const std::pair<char, Weight>& lhs, const std::pair<char, Weight>& rhs) {
                return nodeCosts.at(lhs.first) < nodeCosts.at(rhs.first);
            });
        if (minimum == adjacents.end()) throw std::runtime_error("Node not found!");
        visited.push_back(minimum->first);
        current = minimum->first;
    }
    // Unpacking path
    int total_cost = 0;
    // TODO error handling make sure path is >= 2
    auto visited_first = visited.begin();
    auto visited_second = visited.begin() + 1;
    while (visited_second != visited.end())
    {
        auto adjacents = m_edges.at(*visited_first);
        auto next_node = std::find_if(adjacents.begin(), adjacents.end(),
            [&visited_second](const std::pair<char, Weight>& adj) {
                return adj.first == *visited_second;
            });
        std::cout << " cost from "  << *visited_first << " to " << *visited_second << " : " << next_node->second << std::endl;
        total_cost += next_node->second;
        visited_first++;
        visited_second++;
    }
    std::cout << "total cost: " << total_cost << std::endl;
  }

}
