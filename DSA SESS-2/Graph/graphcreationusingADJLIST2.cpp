//graph creation using adjacency list using vector

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
  public:
  int numVertices;
  vector<vector<int>>adj;//2D vector adjacency matrix

  Graph(int vertices)
  {
    numVertices=vertices;
    adj.resize(numVertices);//it resizes the "adj" vector to have a size of numVertices
  }

  void addEdge(int u, int v)
  {
    adj[u].push_back(v);//undirected graph
    adj[v].push_back(u);
  }

  void printAdjacencyList()
  {
    cout<<"Adjacency List : \n";
    for(int i=0;i<numVertices;i++)
    {
      cout<<i<<"-> ";
      for(int neighbor : adj[i])//It assigns each element of adj[i] to the variable neighbor one at a time.
      {
        cout<<neighbor<<" ";
      }
      cout<<endl;
    }
  }
};

int main()
{
  cout<<"Enter no. of vertices and edges : \n";
  int n,m;
  cin>>n>>m;

  Graph g(n);

  cout<<"Enter the edges in form of u v \n";
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v);
  }

  g.printAdjacencyList();
  return 0;
}