// tarjan's Algorithm 
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 1;
    void dfs(int node , vector<int> adj[] , int parent, vector<int> &vis , int time[] , int low[] ,vector<vector<int>> & bridge){
        vis[node] = 1;
        time[node] = low[node] = timer;
        timer++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it , adj ,node, vis , time , low , bridge);
                low[node] = min(low[node] , low[it]);
                if(low[it] > time[node]){
                    bridge.push_back({node , it});
                }
            }
            else{
                low[node] = min(low[node] , low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n , 0);
        int time[n];
        int low[n];
        vector<vector<int>> bridge;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i , adj , i , vis , time , low , bridge);
            }
        }
        return bridge;
    }
};