#ifndef JUG_H
#define JUG_H

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

struct Node
{
  int a;
  int b;
  int c; //cost

  vector<string> actions;

  bool operator>(const Node &other) const)
{
  return cost > other.cost;
}

};

class Jug
{
  public:
    Jug(int Ca, int Cb, int N, int cfA, int cfB, int ceA, int ceB, int cpAB, int cpBA);

    int solve(string &solution);

  private:
    int Ca;
    int Cb;
    int N;
    int cfA;
    int cfB;
    int ceA;
    int ceB;
    int cpAB;
    int cpBA;

    bool isValidInput();

    bool dijkstra(string &solution);
};

#endif