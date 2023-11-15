
// input -> n - 5
// m - 6

//2 1 1 3 3 4 2 4 2 5 4 5

//output : 
// Enter the no of node and no of edges : 5 6
// the nodes are :5
// the edges are :6
// 2 1 1 3 3 4 2 4 2 5 4 5

// adj list :
// 0 - >
// 1 - > 3
// 2 - > 1  4  5
// 3 - > 4  
// 4 - > 5
// 5 - >

#include<iostream>
#include<vector>
using namespace std;

int main(){
        int n , m;
        cout<<"Enter the no of node and no of edges :";
        cin>>n;
        cin>>m;
        cout<<"the nodes are :"<<n<<endl;
        cout<<"the edges are :"<<m<<endl;
        //the graph is one based indexing 
        //if zero based indexing then it will be works on vector<int> adj[n]
        vector<int> adj[n+1];
        //there is m line of edges
        for(int i = 0; i<m; i++){
            int n1 , n2;
            cin >> n1;
            cin>>n2;
            adj[n1].push_back(n2);

        }
        cout<<endl;
        cout<<"adj list : "<<endl;
        for(int i = 0 ; i <= n; i++){
            cout<<i << " - > ";
            for(auto ele : adj[i]){
                cout<< ele << "  ";
            }
            cout<<endl;
        }

    return 0;
}
