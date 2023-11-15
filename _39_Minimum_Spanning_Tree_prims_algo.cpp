#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
        //{dist , node}
        pq.push({0 , 0});
        vector<int>vis(v , 0);
        int sum = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;
            for(auto it : adj[node]){
                int adjnode = it[0];
                int edge = it[1];
                if(!vis[adjnode]){
                    pq.push({edge , adjnode});
                }
            }
        }
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{

    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj[V];
    int i=0;
    while (i++<E) {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1,t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }
    
    Solution obj;
    cout << obj.spanningTree(V, adj) << "\n";
    

    return 0;
}


// } Driver Code Ends