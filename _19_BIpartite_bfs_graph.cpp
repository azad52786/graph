// 4 4
// 0 2
// 0 3
// 1 3
// 2 3
#include<bits/stdc++.h>
using namespace std;


class Solution {
    private:
    bool bfs(int start , vector<int> adj[] , vector<int> &color){
        
        queue<int> q;
        int clr = 0;
        color[start] = 0;
        q.push(start);

                
        while (!q.empty()) {
            int node = q.front();
            q.pop();


            for (auto it : adj[node]) {
                if (color[it] == -1) {
                    q.push(it);
                    color[it] = !color[node];
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(int v, vector<int> adj[]) {
        vector<int> color(v, -1);
        
        for(int i = 0; i < v; i++){
            if(color[i] == -1){
                bool ans = bfs(i , adj , color);
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