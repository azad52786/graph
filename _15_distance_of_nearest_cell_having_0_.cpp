// Enter the number of rows and columns: 3 3
// Enter the matrix elements (0s and 1s):
// 0 0 0
// 0 1 0
// 1 0 0
// Distances from the nearest 0s:
// 2 1 2
// 1 0 1
// 0 1 2

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int mark = q.front().second;
            dis[row][col] = mark;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && !vis[newrow][newcol]) {
                    vis[newrow][newcol] = 1;
                    q.push({{newrow, newcol}, mark + 1});
                }
            }
        }

        return dis;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the matrix elements (0s and 1s):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    Solution solution;
    vector<vector<int>> ans = solution.updateMatrix(mat);

    cout << "Distances from the nearest 0s:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
