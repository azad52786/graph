#include<bits/stdc++.h>
using namespace std;


class DisjointSet{
    public: 
    vector<int> size , parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int u){
        if(u == parent[u]){
            return u;
        }
        return parent[u] = find_parent(parent[u]);
    }

    void unionBySize(int u , int v){
        int ultimate_parent_of_u = find_parent(u);
        int ultimate_parent_of_v = find_parent(v);

        if(size[ultimate_parent_of_u] > size[ultimate_parent_of_v]){
            parent[ultimate_parent_of_v] = ultimate_parent_of_u;
            size[ultimate_parent_of_u] += size[ultimate_parent_of_v];
        }
        else{
            parent[ultimate_parent_of_u] = ultimate_parent_of_v;
            size[ultimate_parent_of_v] += size[ultimate_parent_of_u];            
        }
    }
};
class Solution{
    public:
        int minimumConnections(int n , vector<vector<int>> &edges){
        DisjointSet ds(n);
        int extra = 0;
       for(auto it : edges){
           int u = it[0];
           int v = it[1]; 
            if(ds.find_parent(u) == ds.find_parent(v)){
                extra++;
            }
            else{
                ds.unionBySize(u , v);
            }
        } 
        int compo = 0;
        for(int i = 0; i < n; i++){
            if(ds.parent[i] == i){
                compo++;
            }
        }
        int minimumExtraConnections = compo - 1;
        if (extra >= minimumExtraConnections) {
            return minimumExtraConnections;
        } else {
            return -1;
        }
}
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> connections(m,vector<int> (2));
        for(auto &j:connections)
            cin>>j[0]>>j[1];
        Solution s;
        cout<<s.minimumConnections(n,connections)<<endl;
    }
    return 0;
}