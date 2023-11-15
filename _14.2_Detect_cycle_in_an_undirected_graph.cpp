#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int src, int vis[], vector<int> adj[], int parent) {
        vis[src] = 1;
        for (auto it : adj[src]) {
            if (!vis[it]) {
                bool ans = dfs(it, vis, adj, src);
                if (ans == true)
                    return true;
            } else if (it != parent)
                return true;
        }
        return false;
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        int vis[n] = {0};
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bool ans = dfs(i, vis, adj, -1);
                if (ans) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of nodes and number of edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1];

    cout << "Enter the edges:\n";
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    Solution solution;
    
    bool ans = solution.isCycle(n, adj);
    if (ans) {
        cout << "The graph has a cycle";
    } else {
        cout << "The graph has no cycle";
    }
    
    return 0;
}
