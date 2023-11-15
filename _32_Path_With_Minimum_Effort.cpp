
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        priority_queue<pair<int , pair<int, int>> , vector<pair<int,pair<int , int>>> ,
        greater<pair<int,pair<int ,int >>>> pq;
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distant(n , vector<int>(m , 1e9));
        distant[0][0] = 0;
        //{dist , {row , col}}
        pq.push({0 , {0 , 0}});
        int delrow[] = {-1 , 0 , 1 , 0};
        int delcol[] = {0 , 1 , 0 , -1};
        while(!pq.empty()){
            auto it = pq.top();
            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            // it is go through all the path and find the maximam of all the path that is minimum 
            if(row == n - 1 && col == m - 1) return dist;
            
            for(int i = 0; i < 4 ; i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if(newrow >= 0 && newrow < n && newcol >= 0 &&  newcol < m){
                    //take care of this line you have to take mininimum of all the maximum 
                    int newdis =max(dist , abs(grid[row][col] - grid[newrow][newcol])) ;
                    if(newdis < distant[newrow][newcol]){
                        distant[newrow][newcol] = newdis;
                        pq.push({newdis , {newrow , newcol}});
                    }   
                }
            }
        }
        return 0;
    }
};

int main() {

    int n,m; cin>>n>>m;
    vector<vector<int>> heights;
    
    for(int i=0; i<n; ++i){
        vector<int> temp;
        for(int j=0; j<m; ++j){
            int x; cin>>x;
            temp.push_back(x);
        }
        heights.push_back(temp);
    }
    
    Solution obj;
    cout<<obj.MinimumEffort(heights)<<"\n";
    
    return 0;
}
