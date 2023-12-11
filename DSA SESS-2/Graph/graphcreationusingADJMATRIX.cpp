#include<iostream>
#include<vector>
using namespace std;

class Graph
{
  public:
  int numVertices;
  vector<vector<int>>adj;

  Graph(int numVertices)
  {
    this->numVertices=numVertices;
    //initializing all elements of adjacency matrix to 0
    adj.resize(numVertices,vector<int>(numVertices,0));
  }

  void addEdge(int u,int v)
  {
    adj[u][v]=1;//edge from u to v
    adj[v][u]=1;//1 represents presents of edge between u and v
  }

  void display_matrix()
  {
    for(int i=0;i<numVertices;i++)
    {
      for(int j=0;j<numVertices;j++)
      {
        cout<<adj[i][j]<<" ";
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

  cout<<"Enter pair of vertices btw them edges are there \n";
  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v);
  }

  
  g.display_matrix();
  return 0;
}