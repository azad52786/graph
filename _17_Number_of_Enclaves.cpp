// same as privious problem 
// let's solve using bfs

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<int , int>>q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j] == 1 && !vis[i][j]){
                   vis[i][j] = 1;
                   q.push({i , j});
                }
            }
        }


        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && !vis[newrow][newcol]){
                    q.push({newrow , newcol});
                    vis[newrow][newcol] = 1;
                }
            }
        }




        int cnt = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main(){
        vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution solution;
    int ans =  solution.numEnclaves(grid);

    cout<<"the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves is :"<<ans;
    
    return 0;
}