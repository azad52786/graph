
#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    vector<int>size , parent;
    public:
    //constructor
    DisjointSet(int n){
        size.resize(n+1 , 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    // find parent  
    int find_parent(int u){
        if(u == parent[u]){
            return u;
        }

        return parent[u] = find_parent(parent[u]);
    }

    //unionBySize

    void unionBySize(int u , int v){
        int ultimate_paretn_of_u = find_parent(u);
        int ultimate_paretn_of_v = find_parent(v);

        if(size[ultimate_paretn_of_u] > size[ultimate_paretn_of_v]){
            parent[ultimate_paretn_of_v] = ultimate_paretn_of_u;
            size[ultimate_paretn_of_u] += size[ultimate_paretn_of_v];
        }
        else{
            parent[ultimate_paretn_of_u] = ultimate_paretn_of_v;
            size[ultimate_paretn_of_v] += size[ultimate_paretn_of_u];
        }       
    }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        //{wt , {adj , node}}
        vector<pair<int , pair<int , int>>> edges;
        // O(m)
        for (int i = 0; i < v; i++) {
            for (auto p : adj[i]) {
                int adjnode = p[0];
                int wt = p[1];
                int node = i;
                edges.push_back({wt, {node, adjnode}});
            }
        }
        // O(mlogm)
        sort(edges.begin() , edges.end());
        
        int mstw = 0;
        DisjointSet ds(v);
        // O(m * 4 * alpha)
        for(auto it : edges){
            int wt = it.first;
            int node1 = it.second.first;
            int node2 = it.second.second;
            
            if(ds.find_parent(node1) != ds.find_parent(node2)){
                mstw += wt;
                ds.unionBySize(node1 , node2);
            }
        }
        return mstw;
    }
};




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


