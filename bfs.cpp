#include<iostream>
#include<bits/stdc++.h>

// #include<vector>

using namespace std;

class Graph
{

        int v;
        vector<list<int>> adj;

    public:
        //add graph with v no of items
        Graph(int v){

            this->v=v;
            adj.resize(v);
        }

        //assign value to each edge
        void Add_Edge(int v,int w){
            adj[v].push_back(w);
        }

        void BFS(int start){
            //Breadth first search function
            
            list<int> queue;//queue to pop out last element for traversal

            bool visited[v]={false};// to keep track of the traversed elements
           
            int i=start; //start the iteration with the visited[start] element 
            // visited[i]=true;
            // queue.push_back(i);
            while(i!=-1) { //exit when all elements are visited


                if (visited[i]!=true){
                    // cout << i<< " "<<" -> ";

                    visited[i]=true;
                    queue.push_back(i);
                    cout << queue.front()<< " "<<" -> ";

                    // visited[i]=true;

                }

                queue.pop_front();

                for (auto  j = adj[i].begin(); j!=adj[i].end(); j++) { //traverse the whole adj[i]
                    if (visited[*j]==true){//before push check if already visited 
                        break;
                    }
                    queue.push_back(*j);//add not visited to queue
                    visited[i]=true;

                }
                if (queue.empty())
                    i=-1; //if queue is empty all elements visited
                else
                    i=queue.front();
                    // cout << i<< " "<<" -> ";

                    // queue.pop_front();


                
            }
        }
        void Print(int v){
            int i;
            cout<<"\n"<<v<<" : "<<endl;
            for (auto  i = adj[v].begin(); i!=adj[v].end(); i++) {
                cout << *i << " "<<" -> ";

            }

        }
};


int main(){

    Graph g(4);
    g.Add_Edge(0, 1);
    g.Add_Edge(0, 2);
    g.Add_Edge(1, 2);
    g.Add_Edge(2, 0);
    g.Add_Edge(2, 3);
    g.Add_Edge(3, 3);  
   /* g.Print(0); 
    g.Print(1); 
    g.Print(2); 
    g.Print(3); 
    g.BFS(2);
    */
   //k 
    g.BFS(2);


    return 0;
}