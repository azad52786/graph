#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board , vector<vector<int>>& vis , int row ,int col){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        for(int i = 0; i < 4; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol] && board[newrow][newcol] == 'O'){
                dfs(board , vis , newrow , newcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n  = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));


        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && board[i][j] == 'O' && !vis[i][j]){
        //             dfs(board , vis , i , j);
        //         }
        //     }
        // }





        //for first row and last row

        for(int i = 0; i < m; i++){
            if( board[0][i] == 'O' && !vis[0][i]){
                dfs(board , vis , 0 , i);
            }
            if( board[n-1][i] == 'O' && !vis[n-1][i]){
                dfs(board , vis , n-1 , i);
            }
        }

        //for first col and last col

        for(int i = 0; i < n; i++){
            if( board[i][0] == 'O' && !vis[i][0]){
                dfs(board , vis , i , 0);
            }
            if( board[i][m-1] == 'O' && !vis[i][m-1]){
                dfs(board , vis , i , m-1);
            }
        }



        for(int i = 0; i < n; i++){
            for(int j = 0; j < m ; j++){
                if(board[i][j] == 'O' && !vis[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

int main(){
       vector<vector<char>> grid = {
        {'X' , 'X' , 'X' , 'X'},
        {'X' , 'O' , 'O' , 'X'},
        {'X' , 'X' , 'O' , 'X'},
        {'X' , 'O' , 'X' , 'X'}
       };

       Solution solution;

        solution.solve(grid);

        for(int i = 0; i < 4 ; i++){
            for(int j = 0 ; j  < 4; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    return 0;
}