// implimentation of djikstra algorithm by using priority queue


#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int s)
    {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int >> > pq;
        vector<int>dist(n , 1e9);
        pq.push({0 , s});
        dist[s] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it[0];
                int wei = it[1];
                int newdis = wei + dis;
                if(newdis < dist[adjnode]){
                    dist[adjnode] = newdis;
                    pq.push({newdis , adjnode});
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
