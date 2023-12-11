//dikshtraj shortest path

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // A very large value to represent infinity

void dj(int n, vector<vector<int>>& adj) {
    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If there's a shorter path from i to j through k, update it
                if (adj[i][k] != INF && adj[k][j] != INF) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
}

int main() {
    int n; 
    cout << "Enter the number of nodes: ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, INF));

    // Input the adjacency matrix (initial distances)
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    // Call dj to find shortest paths
    dj(n, adj);

    // Print the result
    cout << "Shortest paths between all pairs of nodes:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == INF) {
                cout << "INF\t";
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
