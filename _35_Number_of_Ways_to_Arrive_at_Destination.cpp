
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long , long long>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        long long mod = (long long)(1e9 + 7);
        vector<long long> dist(n , LONG_MAX);
        vector<long long> ways(n , 0);
        ways[0] = 1;
        dist[0] = 0;
        priority_queue<pair<long long, long long> , vector<pair<long long , long long>> , greater<pair<long long , long long>>>pq;
        //{dist , node}
        pq.push({0 , 0});
        while(!pq.empty()){
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                long long adjnode = it.first;
                long long edgweight = it.second;
                
                long long newdis = dis + edgweight;
                
                if(newdis < dist[adjnode]){
                    dist[adjnode] = newdis;
                    pq.push({newdis , adjnode});
                    ways[adjnode] =( ways[node]);
                }
                else if(newdis == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;    }
};


int main() {

        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    

    return 0;
}