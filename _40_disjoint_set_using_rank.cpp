#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank , parent;
    public:
    //constructor
    DisjointSet(int n){
        rank.resize(n+1 , 0);
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

        parent[u] = find_parent(parent[u]);
    }

    //unionByRank

    void unionByRank(int u , int v){
        int ultimate_paretn_of_u = find_parent(u);
        int ultimate_paretn_of_v = find_parent(v);

        if(rank[ultimate_paretn_of_u] > rank[ultimate_paretn_of_v]){
            parent[ultimate_paretn_of_v] = ultimate_paretn_of_u;
        }
        else if(rank[ultimate_paretn_of_v] > rank[ultimate_paretn_of_u]){
            parent[ultimate_paretn_of_u] = ultimate_paretn_of_v;
        }
        else{
            parent[ultimate_paretn_of_u] = ultimate_paretn_of_v;
            rank[ultimate_paretn_of_v]++;
        }
        
    }
};

int main(){
       DisjointSet ds(7);
       ds.unionByRank(1 , 2);
       ds.unionByRank(2 , 3);
       ds.unionByRank(4 , 5);
       ds.unionByRank(6 , 7);
       ds.unionByRank(5 , 6);
       if(ds.find_parent(1) == ds.find_parent(7)){
        cout<<"same component\n";
       }
       else{
        cout<<"Is not in same component\n";
       }
       ds.unionByRank(3 , 7);
       if(ds.find_parent(1) == ds.find_parent(7)){
        cout<<"same component\n";
       }
       else{
        cout<<"Is not in same component\n";
       }
    return 0;
}