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

int main(){
       DisjointSet ds(7);
       ds.unionBySize(1 , 2);
       ds.unionBySize(2 , 3);
       ds.unionBySize(4 , 5);
       ds.unionBySize(6 , 7);
       ds.unionBySize(5 , 6);
       if(ds.find_parent(1) == ds.find_parent(7)){
        cout<<"same component\n";
       }
       else{
        cout<<"Is not in same component\n";
       }
       ds.unionBySize(3 , 7);
       if(ds.find_parent(1) == ds.find_parent(7)){
        cout<<"same component\n";
       }
       else{
        cout<<"Is not in same component\n";
       }
    return 0;
}