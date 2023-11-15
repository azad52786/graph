// Enter the row and col :3 3  
// 1 1 1
// 2 2 0
// 2 2 2


#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int row , int col , int color , int initial_color , int delrow[]  , int delcol[] , vector<vector<int>>& image , vector<vector<int>> &ans){
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = color;
        for(int i = 0; i < 4;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && image[newrow][newcol] == initial_color && ans[newrow][newcol] != color){
                
                dfs(newrow , newcol , color , initial_color , delrow , delcol , image , ans);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initial_color = image[sr][sc];

        int del_row[] = {-1 , 0 , 1 , 0};
        int del_col[] = {0 , 1 , 0 , -1};

        dfs(sr , sc , color , initial_color , del_row , del_col , image , ans );

        return ans;
    }
};


int main(){
        int n , m;
        cout<<"Enter the row and col :" ;
        cin>>n >> m;
       vector<vector<int>> image(n , vector<int>(m));
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m ;j++){
            cin>>image[i][j];
        }
       }
       cout<<endl;

        Solution solution;
        int color = 3;
        int sr = 2;
        int sc = 0;
        vector<vector<int>> ans = solution.floodFill(image,sr,sc,color);
       for(int i = 0; i < n; i++){
        for(int j = 0; j < m ;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
       }
    return 0;
}