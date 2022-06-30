#include <bits/stdc++.h>
#include "graph_path_using_dfs1.h"
#include <iostream>
using namespace std;


int main() {
  Graph g(4);
  g.Add_Edge(0, 1);
  g.Add_Edge(1, 2);
  g.Add_Edge(1, 3);
  g.Add_Edge(2, 0);
  g.Add_Edge(2, 3);
  g.Add_Edge(3, 0);
  if (g.DFS(0, 2))
    cout << "\nPath exits" << endl;
  else
    cout << "\nno path exits" << endl;

  return 0;
}