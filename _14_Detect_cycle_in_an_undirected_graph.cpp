#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool bfs(int src , int vis[] , vector<int> adj[]){
        // {children , parent}
        queue<pair<int , int>> q;
        q.push({src , -1});
        vis[src] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentnode : adj[node]){
                if(!vis[adjacentnode]){
                    vis[adjacentnode] = 1;
                    q.push({adjacentnode , node});
                }
                //it is visited but the adjacentnode is not the parent of the node 
                else if(adjacentnode != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        int vis[n] = {0};
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                bool ans = bfs(i , vis , adj);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    int n , m;
    cout<<"Enter the no of node and no of edges :";
    cin>>n;
    cin>>m;
    cout<<"the nodes are :"<<n<<endl;
    cout<<"the edges are :"<<m<<endl;
    
    //zero based indexing
    vector<int> adj[n + 1];
    //there is m line of edges
    for(int i = 0; i<m; i++){
        int n1 , n2;
        cin >> n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

    Solution solution;
    
    bool ans = solution.isCycle(n, adj);
    if(ans){
        cout<<"The graph has cycle";
    }
    else{
        cout<<"The graph has not any cycle";
    }
    return 0;
}