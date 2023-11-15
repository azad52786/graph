//input:

// Enter the no of row and no of col :3 3
// 0 1 2
// 0 1 1
// 2 1 1

//output:
// The no of times required to rotten all the oranges is :2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // {{row , col}, time}
        queue<pair<pair<int , int> , int>>q;
        vector<vector<int>> vis = grid;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0});
                }
            }
        }
        int time = 0;
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time , t);

            for(int i = 0; i < 4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && vis[newrow][newcol] != 2 && grid[newrow][newcol] == 1){
                    q.push({{newrow , newcol} , t + 1});
                    vis[newrow][newcol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 1) return -1;
            }
        }
        return time;
    }
};

int main(){
       int n  , m;
       cout<<"Enter the no of row and no of col :";
       cin>>n>>m;
       vector<vector<int>>grid(n , vector<int>(m));

       for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
       }

        Solution solution;

        int ans = solution.orangesRotting(grid);

        cout<<"The no of times required to rotten all the oranges is :" <<ans;

    return 0;
}