//input: 
// Enter no of node and Edge :8 8
// The nodes are :8
// The edges are :8
// Enter all the edges :0 1 1 4 1 5 2 3 2 6 6 7 3 7 0 2

// output
// The dfs traversal is :0 1 4 5 2 3 7 6


#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    vector<int> dfs(int node , int vis[] , vector<int> &ans , vector<int> adj[]){
        vis[node] = 1;
        ans.push_back(node);
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it , vis , ans , adj);
            }
        }
        return ans;
    }
    public:
    vector<int> dfsTraversal(int node , vector<int> adj[]){
        int start = 0;
        int vis[node] = {0};
        vector<int>ls;

        vector<int> ans = dfs(start , vis , ls , adj);

        return ans;
    }
};

int main(){
       int n , m;
       cout<<"Enter no of node and Edge :";
       cin>>n>>m;
       cout<<"The nodes are :" <<n<<endl;
       cout<<"The edges are :" <<m<<endl;
       /// zero based indexing
       vector<int> adj[n];
       //createing the adjecency list
       cout<<"Enter all the edges :";
       for(int i = 0; i < m ; i++){
            int n1 , n2;
            cin>>n1>>n2;
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
       }
        Solution solution;
        vector<int> ans = solution.dfsTraversal(n , adj);

        cout<<"The dfs traversal is :";

        for(auto it : ans){
            cout<<it<<" ";
        }
    
    return 0;
}