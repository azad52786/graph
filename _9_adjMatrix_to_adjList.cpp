//input: 
// 5 6
// 2 1 1 3 3 4 2 4 2 5 4 5

//output :
// adj list :
// 0 - >
// 1 - > 2  3
// 2 - > 1  4  5
// 3 - > 1  4
// 4 - > 2  3  5
// 5 - > 2  4

#include<bits/stdc++.h>
using namespace std;

int main(){
       int n , m;
       cin>>n>>m;
       int adjMat[n + 1][n + 1];
       for(int i = 0; i<m ; i++){
            int n1 , n2;
            cin>>n1>>n2;
            adjMat[n1][n2] = 1;
            adjMat[n2][n1] = 1;
       }

        vector<int> adjList[n + 1];
       //convert adjNode to matrix 
        for(int i = 0 ; i <= n; i++){
            for(int j = 0; j <= n; j++){
                //i is not a adj node of i
                if(adjMat[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                }
            }
        }

        cout<<"adj list : "<<endl;
        for(int i = 0 ; i <= n; i++){
            cout<<i << " - > ";
            for(auto ele : adjList[i]){
                cout<< ele << "  ";
            }
            cout<<endl;
        }

    return 0;
}