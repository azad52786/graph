#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 1;
    void dfs(int node , int parent , int time[] , int low[] , vector<int> &vis , vector<int> &mark , vector<int> adj[]){
        vis[node] = 1;
        low[node] = time[node] = timer;
        timer++;
        int children = 0;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it , node , time , low , vis , mark , adj);
                children++;
                low[node] = min(low[it] , low[node]);
                if(low[it] >= time[node] && parent != -1){
                    mark[node] = 1;
                }
            }
            else{
                low[node] = min(low[node] , time[it]);
            }
            if(children > 1 && parent == -1) mark[node] = 1;
        }
    }
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        int time[n];
        int low[n];
        vector<int>vis(n , 0);
        vector<int>mark(n , 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i , -1 , time , low , vis , mark , adj);
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        if(ans.size() >= 1) return ans;
        else return {-1};
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
    vector<int> ans = obj.articulationPoints(V, adj);
    for(auto i: ans)cout << i << " ";
    cout << "\n";

	return 0;
}
