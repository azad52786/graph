//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
    void dfs(int src , vector<pair<int , int>> adj[] , stack<int> &st , vector<int> &vis){
        vis[src] = 1;
        for(auto it : adj[src]){
            if(!vis[it.first]){
                dfs(it.first , adj , st , vis);
            }
        }
        st.push(src);
    }
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int , int> > adj[n];
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back({edges[i][1] , edges[i][2]});
        }
        vector<int> vis(n , 0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i , adj , st , vis);
            }
        }
        vector<int> dist(n , 1e9);
        //make the src node distance as zero(0)
        //it is importent to do that 
        dist[0] = 0;
        while(!st.empty()){
            int item = st.top();
            st.pop();
            for(auto it : adj[item]){
                int v = it.first;
                int wt = it.second;
                if(dist[item] + wt < dist[v]){
                    dist[v] = dist[item] + wt;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    for(int i=0; i<m; ++i){
        vector<int> temp;
        for(int j=0; j<3; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }
    Solution obj;
    vector<int> res = obj.shortestPath(n, m, edges);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << "\n";

}

// } Driver Code Ends