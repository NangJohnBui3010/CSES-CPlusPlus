#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n, m;
vector<vector<int>> G;  // Adjacency list for the graph
vector<int> parent;     // To track the parent of each node
vector<int> cycle;      // To store the resulting cycle
vector<int> visited;    // Visited status of each node
bool found = false;     // To mark if a cycle is found

// DFS function to detect a cycle
void DFS(int node, int par) {
    visited[node] = 1;
    parent[node] = par;

    for (int neighbor : G[node]) {
        if (neighbor == par) continue; // Skip the parent node

        if (!visited[neighbor]) {
            DFS(neighbor, node);
            if (found) return;
        } else if (visited[neighbor] == 1) {
            // Cycle found, backtrack to build the cycle
            found = true;
            cycle.push_back(neighbor);
            for (int v = node; v != neighbor; v = parent[v]) {
                cycle.push_back(v);
            }
            cycle.push_back(neighbor); // Complete the cycle
            return;
        }
    }
    
    visited[node] = 2; // Mark as fully visited
}

int main() {
    cin >> n >> m;
    G.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, 0);

    // Reading the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    // Run DFS from each unvisited node
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i, -1);
            if (found) break; // Stop when a cycle is found
        }
    }

    // Output result
    if (found) {
        cout << cycle.size() << endl;
        reverse(cycle.begin(), cycle.end()); // Reverse to get the correct order
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE" << endl; // No cycle found
    }

    return 0;
}