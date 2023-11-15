
#include <bits/stdc++.h>
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

       return  parent[u] = find_parent(parent[u]);
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
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& grid) {
       int n = grid.size();
       DisjointSet ds(n); 
       sort(grid.begin() , grid.end());
       unordered_map<string , int> mpp;
       for(int i = 0; i < n; i++){
           for(int j = 1 ; j < grid[i].size(); j++){
               if(mpp.find(grid[i][j]) == mpp.end()){
                   mpp[grid[i][j]] = i;
               }
               else{
                   ds.unionByRank(mpp[grid[i][j]] , i);
               }
           }
       }
       
      vector<vector<string>> mails(n);
       for(auto it : mpp){
           string mail = it.first;
           int parent = it.second;
           int ultimate_parent = ds.find_parent(parent);
           mails[ultimate_parent].push_back(mail);
        } 

        vector<vector<string>> ans;
        for(int i = 0; i < n ; i++){
            vector<string> temp;
            if(mails[i].size() == 0) continue;
            sort(mails[i].begin() , mails[i].end());
            temp.push_back(grid[i][0]);
            for(int j = 0; j < mails[i].size(); j++){
                temp.push_back(mails[i][j]);
            }
            ans.push_back(temp);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}
