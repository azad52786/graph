
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<pair<int , int>> bfs(vector<vector<int>>& grid , vector<vector<int>>& vis , int baserow , int basecol){
        int n = grid.size();
        int m = grid[0].size();
        vis[baserow][basecol] = 1;
        // {i , j}
        queue<pair<int , int>>q;
        vector<pair<int , int>> ans;
        q.push({baserow , basecol});
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            ans.push_back({row - baserow , col - basecol});
            for(int i = 0; i < 4; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol] && grid[newrow][newcol] == 1){
                    q.push({newrow , newcol});
                    vis[newrow][newcol] = 1;
                }
            }
            
        }
        return ans;
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        set<vector<pair<int , int>>>s;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                   vector<pair<int , int>>ans = bfs(grid , vis , i , j); 
                    s.insert(ans);
                }  
            }
        }
        return s.size();
    }
};




int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    cout << obj.countDistinctIslands(grid) << endl;
}
