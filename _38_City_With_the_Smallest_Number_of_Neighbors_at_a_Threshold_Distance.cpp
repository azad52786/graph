#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<vector<int>>adj(n , vector<int>(n , 1e9));
        for(auto it : edges){
            adj[it[0]][it[1]] = it[2];
            adj[it[1]][it[0]] = it[2];
        }
        for (int i = 0; i < n; i++) adj[i][i] = 0;
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if (adj[i][via] == INT_MAX || adj[via][j] == INT_MAX)
						continue;
					adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
        int city = -1;
        int mincnt = INT_MAX;
        for(int i = 0; i < n; i++){
            int thresholdCnt = 0;
            for(int j = 0; j < n; j++){
                if(adj[i][j] <= distanceThreshold){
                    thresholdCnt++;
                }
            }
            if(thresholdCnt <= mincnt){
                mincnt = thresholdCnt;
                city = i;
            }
        }
        return city;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;
    // n--;
    for (int i = 0; i < m; ++i) {
        vector<int> temp;
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }

    int dist;
    cin >> dist;
    Solution obj;
    cout << obj.findCity(n, m, adj, dist) << "\n";
    
}
