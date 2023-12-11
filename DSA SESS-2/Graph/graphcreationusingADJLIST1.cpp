//creation of graph using adjacency list using unordered map

#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
using namespace std;
template <typename T>
class graph
{
  public:
  unordered_map<T, list<T>>adj;

  void addEdge(T u, T v, bool direction)
  {
    //direction=0 -> undirected graph
    //direction=1 -> directed graph

    //create edge from u to v
    adj[u].push_back(v);

    if(direction == 0)
    {
      adj[v].push_back(u);//create edge from v to u if undirected graph
    }
  }

  void printAdjList()
  {
    for(auto i:adj)//it means i belongs to adj list
    {
      cout<<i.first<<"-> ";
      for(auto j:i.second)//it means j belongs to i.second 
      {
        cout<<j<<",";
      }
      cout<<endl;
    }
  }
};

int main()
{
  int n;
  cout<<"Enter no. of nodes : "<<endl;
  cin>>n;

  int m;
  cout<<"Enter no. of edges : "<<endl;
  cin>>m;

  graph<int> g;

  for(int i=0;i<m;i++)
  {
    int u,v;
    cin>>u>>v;
    g.addEdge(u,v,0);//undirected graph
  }

  g.printAdjList();
  return 0;
}


//  Adjacency list using vector

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>>&edges)
{
  vector<int> ans[n]; //to store neighbours
  for(int i=0;i<m;i++)
  {
    int u = edges[i][0];//ith row, 0th col
    int v = edges[i][1];

    ans[u].push_back(v);
    ans[v].push_back(u);
  }

  vector<vector<int>>adj;
  for(int i=0;i<n;i++)
  {
      adj[i].push_back(i);

      for(int j=0;j<ans[i].size();j++)
      {
        adj[i].push_back(ans[i][j]);
      }
  }
  return adj;
}

int main()
{
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges in the format 'u v' (0-based indexing):\n";
    for(int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adjacencyList = printAdjacency(n, m, edges);

    cout << "Adjacency List:\n";
    for(int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < adjacencyList[i].size(); j++)
        {
            cout << adjacencyList[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}