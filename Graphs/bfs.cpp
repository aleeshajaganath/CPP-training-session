#include <bits/stdc++.h>

#include <iostream>
using namespace std;

/*
    Graph class is used to impliment graph and do breadth first search
    Graph(int V)         : construtor to initailize no of vertices a graph has
    Add_Edge(int v,int w): add edges to  graph "adj"
    BFS(int start)       : does the breadth first search of a graph
*/

class Graph {
  int v;
  vector<list<int>> adj;

 public:
  // add graph with v no of items
  Graph(int v) {
    this->v = v;
    adj.resize(v);
  }

  // assign value to each edge
  void Add_Edge(int v, int w) { adj[v].push_back(w); }

  void BFS(int start) {
    // Breadth first search function
    list<int> queue;  // queue to pop out last element for traversal
    int j;
    bool visited[v];  // to keep track of the traversed elements
    int i = start;    // start the iteration with the visited[start] element
    for (j = 0; j < v; j++) {
      visited[j] = false;
    }

    while (i != -1) {  // exit when all elements are visited
      if (visited[i] != true) {
        visited[i] = true;
        queue.push_back(i);
        cout << queue.front() << " "
             << " -> ";
      }
      queue.pop_front();

      for (auto j = adj[i].begin(); j != adj[i].end();
           j++) {                   // traverse the whole adj[i]
        if (visited[*j] == true) {  // before push check if already visited
          break;
        }
        queue.push_back(*j);  // add not visited to queue
        visited[i] = true;
      }
      if (queue.empty())
        i = -1;  // if queue is empty all elements visited
      else
        i = queue.front();
    }
  }

  //  to display all edges from start to v only
  void Print(int v) {
    int i;
    cout << "\n" << v << " : " << endl;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++) {
      cout << *i << " "
           << " -> ";
    }
  }
};

int main() {
  // create a graph containing 4 nodes
  Graph g(4);
  // add edges
  g.Add_Edge(0, 1);
  g.Add_Edge(0, 2);
  g.Add_Edge(1, 2);
  g.Add_Edge(2, 0);
  g.Add_Edge(2, 3);
  g.Add_Edge(3, 3);
  // call BFS from 2
  g.BFS(2);
  return 0;
}