

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        if(source.first == destination.first && source.second == destination.second) return 0;
        queue<pair<int , pair<int , int>>>q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        dist[source.first][source.second] = 0;
        q.push({0 , {source.first , source.second}});
        while(!q.empty()){
            auto it = q.front();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            q.pop();
            int delrow[] = {-1 , 0 , 1 , 0};
            int delcol[] = {0 , 1 , 0 , -1};
            for(int i = 0; i < 4; i++){
                int newrow = r + delrow[i];
                int newcol = c + delcol[i];
                int newdist = dis + 1;
                if(newrow < n && newrow >= 0 && newcol < m && newcol >= 0 && grid[newrow][newcol] == 1
                && newdist < dist[newrow][newcol]){
                    dist[newrow][newcol] = newdist;
                    if(newrow == destination.first && newcol == destination.second) return newdist;
                    q.push({newdist , {newrow , newcol}});
                }
            }
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
}