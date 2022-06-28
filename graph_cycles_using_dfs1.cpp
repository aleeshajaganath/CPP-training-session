#include<iostream>
#include<bits/stdc++.h>

// #include<vector>

using namespace std;

class Graph
{

        int v;
        vector<list<int>> adj;
        vector<bool> visited;

    public:
        //add graph with v no of items
        Graph(int v){

            this->v=v;
            adj.resize(v);
            visited.resize(v);
            for (size_t i = 0; i < v; i++)
            {
                /* code */
                visited.push_back(false);
            }
            
        }

        //assign value to each edge
        void Add_Edge(int v,int w){
            adj[v].push_back(w);
        }

        // void DFS(int start){
        bool DFS(int start){
            //Depth first search function

            list<int> queue;//queue to pop out last element for traversal
           
            int i=start; //start the iteration with the visited[start] element 
            while(i!=-1) { //exit when all elements are visited

                // travel the i and its childrens ,grand childrens
                while(visited[i]!=true){
                
                        cout<<i<<"->";

                        visited[i]=true;  
                        queue.push_back(i);//add not visited to queue
                        // i=elem;
                        i=queue.back();

                        // cout<<"visited and pushed in queue"<<i<<endl;
                        int count1=1;

                        for (auto elem : adj[i]) {
                        //if childrens are not visited visit them and cont traversal
                            if (visited[elem]==true){
                                // cout<<"\n cycle"<<elem<<endl;
                                cout<<elem;
                                return true;
                                // break;
                            }
                            count1--;
                            // cout <<"new elements "<< elem << endl;
                            // visited[elem]=true;  
                            queue.push_back(elem);//add not visited to queue
                            
                            if (count1==0)
                                break;
                        }
                        i=queue.back();
                        // cout <<"new front elements "<< i << endl;


                    }
                    
                    if (visited[i]==true){
                        visited[i]=true;  

                        if (queue.empty()){
                            i=-1;
                            // cout<<" exit "<<endl;
                            // break;
                            return false;
                        }
                        while(visited[i]!=false){
                            // cycle=true;//found cycle ,found visited node again
                            if (queue.empty()){
                                i=-1;
                                // cout<<"No cycle  found "<<endl;
                                return false;

                                // break;
                            } 
                            queue.pop_back();
                            i=queue.back();
                            bool elements_present=false;
                            for (auto elem : adj[i]) {
                                // cout<<"cycle  found "<<i<<endl;
                                elements_present=true;
                                break;
                            }
                            if (!elements_present)
                            {
                                if (!queue.empty()){
                                        queue.pop_back();
                                        i=queue.back();  
                                        // cout<<"No cycle  found up to "<<i<<endl;
  
                                }else{
                                    i=-1;
                                    // cout<<"No cycle  found "<<endl;

                                }
                            }
                        // break;
                              
                    }   
   
                }
               


                
            }
        }


        void Print(int v){
            // int i;
            // cout<<"\n"<<v<<" : "<<endl;
            for (int j=0;j<=v;j++)
                for (auto  i = adj[j].begin(); i!=adj[j].end(); i++) {
                    cout << "\n"<<j << " "<<" -> "<<*i;

                }

        }
};


int main(){

    Graph g(4);
    g.Add_Edge(0, 1);
    g.Add_Edge(1, 2);
    // g.Add_Edge(1, 3);
    g.Add_Edge(2, 0);
    g.Add_Edge(2, 3);
    // g.Add_Edge(3, 0);  
//    /* 
    // g.Print(0); 
    // g.Print(1); 
    // g.Print(2); 
    // g.Print(3); 
    // g.BFS(2);
    // */
   //k 
    // g.Print(0); 

    if (g.DFS(0))
        cout<<"\ncycles present"<<endl;
    else
        cout<<"\ncycles not present"<<endl;



    return 0;
}