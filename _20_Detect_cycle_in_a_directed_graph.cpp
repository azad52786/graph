
#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int start , vector<int> adj[] , vector<int>&vis_path , vector<int> &vis){
        vis_path[start] = 1;
        vis[start] = 1;
        for(auto it : adj[start]){
            if(!vis[it]){
                if(dfs(it , adj , vis_path , vis) == true) return true;
                
            }
            else if(vis_path[it] == 1){
                return true;
            }
        }
        vis_path[start] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v , 0);
        vector<int>vis_path(v , 0);
        
        for(int i = 0; i < v; i++){
            if(vis[i] == 0){
                bool ans = dfs(i , adj , vis_path , vis);
                if(ans == true) return true;
            }
        }
        return false;
    }
};


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
    bool ans = obj.isCyclic(V, adj);
    if(ans) cout<<"Graph have a cycle"<<endl;
    else cout<<"Graph have not any cycle";


    return 0;
}
