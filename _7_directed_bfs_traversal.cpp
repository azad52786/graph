//this is for directed graph
//input : 
// Enter the no of node and no of edges :5 4 
// the nodes are :5
// the edges are :4
// enter all the edges :0 1 0 2 0 3 2 4

// //output:
// The bfs traversal is :0 1 2 3 4

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> bfsTraversal(int node , vector<int> adj[]){
        vector<int> bfs;
        queue<int> q;
        int vis[node] = {0};
        q.push(0);
        vis[0] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
    
};

int main(){
      int n , m;
        cout<<"Enter the no of node and no of edges :";
        cin>>n;
        cin>>m;
        cout<<"the nodes are :"<<n<<endl;
        cout<<"the edges are :"<<m<<endl;  

        //zero based indexing 
        vector<int> adj[n];
        cout<<"enter all the edges :";
        for(int i = 0; i < m; i++){
            int n1 , n2;
            cin>>n1>>n2;
            adj[n1].push_back(n2);
        }

        Solution solution;

        vector<int> ans = solution.bfsTraversal(n , adj);
        cout<<"The bfs traversal is :";
        for(int i = 0; i < ans.size(); i++){
            cout<<ans[i] << " ";
        }


    return 0;
}