#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void bfs(vector<vector<int>>&grid , vector<vector<int>> &vis , int row , int col){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int , int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int delrow = -1; delrow <= 1; delrow++){
                for(int delcol = -1; delcol <= 1; delcol++){
                    int newrow = row + delrow;
                    int newcol = col + delcol;

                    if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1 && !vis[newrow][newcol]){
                        vis[newrow][newcol] = 1;
                        q.push({newrow , newcol});
                    }
                }
            }
        }
    }
    public:
    int numIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt = 0;
        for(int row = 0 ; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == 1){
                    cnt++;
                    bfs(grid , vis , row , col);
                }
            }
        }
        return cnt;
    }
};

int main(){
    int n , m;
    cout<<"Enter the row and col :";
    cin>>n>>m;
    vector<vector<int>> grid(n , vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    Solution solution;

    int ans = solution.numIslands(grid);

    cout<<"The no of connected components are :" <<ans;

    return 0;
}