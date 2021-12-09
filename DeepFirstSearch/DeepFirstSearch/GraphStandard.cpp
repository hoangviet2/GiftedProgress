//
//  GraphStandard.cpp
//  DeepFirstSearch
//
//  Created by Hoang Viet on 15/10/2021.
//

#include "GraphStandard.hpp"
GraphStd::GraphStd(int V){
    this->size = V;
    adjacencys = new list<int>[V];
       
    tc = new bool* [V];
    for (int i = 0; i < V; i++){
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}
void GraphStd::transitiveClosure(){
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (int i = 0; i < size; i++)
        DSUntil(i, i); // Every vertex is reachable from self.
      
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}
// A recursive DFS traversal function that finds
// all reachable vertices for s.
void GraphStd::DSUntil(int s, int v)
{
    // Mark reachability from s to t as true.
     if(s==v){
        if(find(adjacencys[v].begin(),adjacencys[v].end(),v)!=adjacencys[v].end())
          tc[s][v] = true;
          }
      else
            tc[s][v] = true;
   
    // Find all the vertices reachable through v
    list<int>::iterator i;
    for (i = adjacencys[v].begin(); i != adjacencys[v].end(); ++i)
        if (tc[s][*i] == false)
            DSUntil(s, *i);
}
bool GraphStd::isCyclicUntil(int v,bool visited[], int parent){
     
    // Mark the current node as visited
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    list<int>::iterator i;
    for (i = adjacencys[v].begin(); i !=
         adjacencys[v].end(); ++i)
    {
         
        // If an adjacent vertex is not visited,
        //then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUntil(*i, visited, v))
              return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
           return true;
    }
    return false;
}
bool GraphStd::isCyclic(){
    // Mark all the vertices as not
       // visited and not part of recursion
       // stack
       bool *visited = new bool[size];
       for (int i = 0; i < size; i++)
           visited[i] = false;
    
       // Call the recursive helper
       // function to detect cycle in different
       // DFS trees
       for (int u = 0; u < size; u++)
       {
          
           // Don't recur for u if
           // it is already visited
           if (!visited[u])
             if (isCyclicUntil(u, visited, -1))
                return true;
       }
    return false;
}
