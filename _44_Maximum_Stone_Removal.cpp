#include <bits/stdc++.h>
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol , it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        
        unordered_map<int , int> stoneMap;
        for(auto it : stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow , nodeCol);
            stoneMap[nodeRow] = 1;
            stoneMap[nodeCol] = 1;
        }
        
        int cnt = 0;
        for(auto it : stoneMap){
            if(ds.find_parent(it.first) == it.first){
                cnt++;
            }
        }
        return n - cnt;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}