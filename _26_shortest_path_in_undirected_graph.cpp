//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> adj[n];
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n , 0);
        queue<pair<int , int>> q;
        q.push({src , 0});
        vis[src] = 1;
        vector<int>ans(n , 1e9);
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            ans[node] = dis;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it , dis+1});
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(ans[i] == 1e9){
                ans[i] = -1;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;

    for (int i = 0; i < m; ++i) {
        vector<int> temp;
        for(int j=0; j<2; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        edges.push_back(temp);
    }

    int src; cin >> src;

    Solution obj;

    vector<int> res = obj.shortestPath(edges, n, m, src);

    for (auto x : res){
        cout<<x<<" ";
    }
    cout << "\n";
}

// } Driver Code Ends



// another way to do that question without using visited array

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        vector<int> adj[n];
        for(int i = 0; i < m; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int , int>> q;
        q.push({src , 0});
        vector<int>dist(n , 1e9);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            for(auto it : adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push({it , dist[it]});
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
    
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends