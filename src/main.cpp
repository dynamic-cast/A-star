#include "Graph.h"

#include <map>
#include <vector>

int main (int argc, char* argv[])
{
  std::vector<Graphs::Edge> edges
  {
    {'a', 'z', 75},
    {'a', 's', 140},
    {'a', 't', 118},
    {'b', 'u', 85},
    {'b', 'g', 90},
    {'b', 'p', 101},
    {'b', 'f', 211},
    {'c', 'd', 120},
    {'c', 'r', 148},
    {'c', 'p', 138},
    {'d', 'm', 75},
    {'d', 'c', 120},
    {'e', 'h', 86},
    {'f', 's', 99},
    {'f', 'b', 211},
    {'g', 'b', 90},
    {'h', 'e', 86},
    {'h', 'u', 98},
    {'i', 'n', 87},
    {'i', 'v', 92},
    {'l', 't', 111},
    {'l', 'm', 70},
    {'m', 'l', 70},
    {'m', 'd', 120},
    {'n', 'i', 87},
    {'o', 'z', 71},
    {'o', 's', 151},
    {'p', 'r', 97},
    {'p', 'c', 138},
    {'p', 'b', 101},
    {'r', 's', 80},
    {'r', 'p', 97},
    {'r', 'c', 138},
    {'s', 'o', 151},
    {'s', 'a', 140},
    {'s', 'r', 80},
    {'s', 'f', 99},
    {'t', 'a', 118},
    {'t', 'l', 111},
    {'u', 'b', 85},
    {'u', 'v', 142},
    {'u', 'h', 98},
    {'v', 'u', 142},
    {'v', 'i', 92},
    {'z', 'a', 75},
    {'z', 'o', 71}
  }; // Roadmap of Romania

  Graphs::NodeCosts costs
  {
    {'a', 366},
    {'b', 0},
    {'c', 160},
    {'d', 242},
    {'e', 161},
    {'f', 176},
    {'g', 77},
    {'h', 151},
    {'i', 226},
    {'l', 244},
    {'m', 241},
    {'n', 234},
    {'o', 380},
    {'p', 100},
    {'r', 193},
    {'s', 253},
    {'t', 329},
    {'u', 80},
    {'v', 199},
    {'z', 374}
  }; // Heuristic straight-line distance to Bucharest

  Graphs::Graph g(std::move(edges));
  g.shortestPath('a', 'b', costs);
}
