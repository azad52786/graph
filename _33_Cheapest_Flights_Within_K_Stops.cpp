#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > K)
                continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;
                if (cost + edW < dist[adjNode] && stops <= K)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }
        // If the destination node is unreachable return ‘-1’
        // else return the calculated dist from src to dst.
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};

int main() {
    int n; cin>>n;
    int edge; cin>>edge;
    vector<vector<int>> flights;
    
    for(int i=0; i<edge; ++i){
        vector<int> temp;
        for(int j=0; j<3; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        flights.push_back(temp);
    }
    
    int src,dst,k;
    cin>>src>>dst>>k;
    Solution obj;
    cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    
    return 0;
}
