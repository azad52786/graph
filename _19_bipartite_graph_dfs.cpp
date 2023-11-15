
#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    bool dfs(int start , vector<int> adj[] , vector<int> &color , int clr){
        color[start] = clr;
        for(auto it: adj[start]){
            if(color[it] == -1){
                //if any of dfs call returning false then return false;
                bool call_dfs = dfs(it , adj , color , !clr);
                if(call_dfs == false) return false;
            }
            else if(color[it] == color[start]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(int v, vector<int> adj[]) {
        vector<int> color(v, -1);
        int clr = 0;
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                bool ans = dfs(i , adj , color , clr);
                if(ans == false) return false;
            }
        }
        return true;
    }

};

int main(){

    int V, E;
    cin >> V >> E;
    vector<int>adj[V];
    for(int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isBipartite(V, adj);    
    if(ans)cout << "Graph is bipartite\n";
    else cout << "Graph is not bipartite\n";   
	
	return 0;
}
