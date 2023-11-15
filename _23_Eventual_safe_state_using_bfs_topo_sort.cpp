//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int> adjRev[v];
        int indegree[v] = {0};
        for(int i = 0; i < v; i++){
            for(auto it : adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                q.push(i);
            } 
        }
        vector<int> safeNode;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNode.push_back(node);
            for(auto it : adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        sort(safeNode.begin() , safeNode.end());
        return safeNode;
    }
};



//{ Driver Code Starts.

int main() {


    int V, E;
    cin >> V >> E;
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    Solution obj;
    vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
    for (auto i : safeNodes) {
        cout << i << " ";
    }
    cout << endl;
    
}

// } Driver Code Ends