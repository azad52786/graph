
#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        set<pair<int , int>> st;
        vector<int> dist(n , 1e9);
        dist[s] = 0;
        st.insert({0 , s});
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it : adj[node]){
                int adjnode = it[0];
                int wei = it[1];
                int newdis = dis + wei;
                
                if(newdis < dist[adjnode]){
                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode] , adjnode});
                    }
                    dist[adjnode] = newdis;
                    st.insert({newdis , adjnode});
                }
                
            }
        }
        return dist;
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
    int S;
    cin>>S;
    
    Solution obj;
    vector<int> res = obj.dijkstra(V, adj, S);
    
    for(int i=0; i<V; i++)
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
