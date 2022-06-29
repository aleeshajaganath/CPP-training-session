#include <bits/stdc++.h>

#include <iostream>
using namespace std;

/*

*/

class Graph {
  int v;
  vector<list<int>> adj;
  vector<bool> visited;

 public:
  // add graph with v no of items
  Graph(int v) {
    this->v = v;
    adj.resize(v);
    visited.resize(v);
    for (size_t i = 0; i < v; i++) {
      visited.push_back(false);
    }
  }
  bool DFS(int start);
  // assign value to each edge
  void Add_Edge(int v, int w) { adj[v].push_back(w); }
  void Print(int v);
};

// Depth first search function
bool Graph::DFS(int start) {
  list<int> queue;  // queue to pop out last element for traversal
  int i = start;    // start the iteration with the visited[start] element

  while (i != -1) {  // exit when all elements are visited
    // travel the i and its childrens ,grand childrens
    while (visited[i] != true) {
      cout << i << "->";
      visited[i] = true;
      queue.push_back(i);  // add not visited to queue
      i = queue.back();
      int count1 = 1;

      // if childrens are not visited visit them and cont traversal
      for (auto elem : adj[i]) {
        if (visited[elem] == true) {
          cout << elem;
          return true;
        }
        count1--;
        queue.push_back(elem);  // add not visited to queue
        if (count1 == 0) break;
      }
      i = queue.back();
    }

    if (visited[i] == true) {
      visited[i] = true;
      if (queue.empty()) {
        i = -1;
        return false;
      }
      while (visited[i] != false) {
        // found cycle ,found visited node again
        if (queue.empty()) {
          i = -1;
          return false;
        }
        queue.pop_back();
        i = queue.back();
        bool elements_present = false;
        for (auto elem : adj[i]) {
          elements_present = true;
          break;
        }
        if (!elements_present) {
          if (!queue.empty()) {
            queue.pop_back();
            i = queue.back();
          } else
            i = -1;
        }
      }
    }
  }
  return true;
}
// Print the graph upto vertex V from 0
void Graph::Print(int v) {
  for (int j = 0; j <= v; j++)
    for (auto i = adj[j].begin(); i != adj[j].end(); i++) {
      cout << "\n"
           << j << " "
           << " -> " << *i;
    }
}

int main() {
  Graph g(4);
  g.Add_Edge(0, 1);
  g.Add_Edge(1, 2);
  g.Add_Edge(2, 0);
  g.Add_Edge(2, 3);
  if (g.DFS(0))
    cout << "\ncycles present" << endl;
  else
    cout << "\ncycles not present" << endl;
  return 0;
}