#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph
{
  public: 

  int numVertices;
  vector<vector<int>>adj;
  vector<bool>visited;

  Graph(int numVertices)
  {
    this->numVertices = numVertices;
    visited.resize(numVertices,false);
    adj.resize(numVertices,vector<int>(numVertices,0));
  }

  void addEdge(int u, int v)
  {
    adj[u][v]=1;
    adj[v][u]=1;
  }

  void dfsTraversal(int vertex)
  {
    if(visited[vertex] == true)
    {
      return;
    }
    else 
    {
      cout<<vertex<<" ";
      visited[vertex]=true;
    }

    for(int i=0;i<numVertices;i++)
    {
      if(adj[vertex][i] ==  1)
      {
        dfsTraversal(i);
      }
    }
  }
};

int main()
{
  cout<<"Enter total number of vertices and edges respectively"<<endl;
    int x,y;
    cin>>x>>y;

    Graph g (x);

    cout<<"Enter the pair vertices having an edge between them"<<endl;
    for(int i=0; i<y; i++){
        int v,u;
        cin>>v>>u;
        g.addEdge(v,u);
    }  

    cout<<"Enter the vertex from where you want to start TRAVERSAL:"<<endl;
    int m;
    cin>>m;
    g.dfsTraversal(m);
  return 0;
}