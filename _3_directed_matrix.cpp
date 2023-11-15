//i/p: 
// Enter the no of node and no of edges : 5 6
// the nodes are :5
// the edges are :6
// 2 1 1 3 3 4 2 4 2 5 4 5


//output: 
// adj list :
// 0 - >
// 1 - > 3
// 2 - > 1  4  5
// 3 - > 4  
// 4 - > 5
// 5 - >


#include<iostream>
using namespace std;

int main(){
        int n , m;
        cout<<"Enter the no of node and no of edges :"<<endl;
        cin>>n;
        cin>>m;
        cout<<"the nodes are :"<<n<<endl;
        cout<<"the edges are :"<<m<<endl;
        //the graph is one based indexing 
        //if zero based indexing then it will be works on arr[n][n]
        int arr[n+1][n+1] = {0};
        //there is m line of edges
        for(int i = 0; i<m; i++){
            int n1 , n2;
            cin >> n1;
            cin>>n2;
            arr[n1][n2] = 1;
        }
        cout<<endl;
        cout<<"adj matrix : "<<endl;
        for(int i = 1 ; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<< "the connected nodes are :" <<endl;
        for(int i = 0 ; i <= n; i++){
            for(int j = 0; j <= n; j++){
                if(arr[i][j] == 1){
                    cout<<i << " -> " <<j <<endl;
                }
            }
        }
    return 0;
}


