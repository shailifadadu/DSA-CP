//BFS -> breadth first search traversal in graph

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
  public:

  vector<vector<int>>adj;//creating adjacency matrix
  int numVertices;
  vector<bool>visited;

  Graph(int numVertices)
  {
    this->numVertices = numVertices;
    //initialising all elements of visited array
    visited.resize(numVertices,false);
    //initialising all elements of adjacency list
    adj.resize(numVertices,vector<int>(numVertices,0));
  }

  void addEdge(int u, int v)
  {
      adj[u][v]=1;
      adj[v][u]=1;
  }

  void bfsTraversal(int vertex)
  {
    queue<int> q;
    visited[vertex]=true;
    q.push(vertex);

    while(!q.empty())
    {
      //dequeue vertex from queue and print it
      int currentVertex = q.front();
      cout<<currentVertex<<" ";
      q.pop();

      //visit all adjacent vertices of currentVertex that have not been visited
      for(int i=0;i<numVertices;i++)
      {
        if(adj[currentVertex][i] == 1 && visited[i] == false)
        {
          visited[i]=true;
          q.push(i);
        }
      }
    }
  }
};

int main()
{
  cout<<"Enter total no. of vertices and edges \n";
  int n,m;
  cin>>n>>m;

  Graph g(n);

  //creating graph
  cout<<"Enter the pair of vertices having edge btw them \n";
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v);//undirected graph
  }

  cout<<"Enter vertex from where u want to start traversal \n";
  int x;
  cin>>x;
  g.bfsTraversal(x);

  return 0;
}