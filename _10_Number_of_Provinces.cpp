#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<int> adjList[], vector<int> &vis) {
        vis[node] = 1;
        for (auto it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adjMat) {
        int n = adjMat.size();
        vector<int> adjList[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMat[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adjList, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    int n, m;
    cout << "Enter the no of node and no of edges :" << endl;
    cin >> n;
    cin >> m;
    cout << "the nodes are :" << n << endl;
    cout << "the edges are :" << m << endl;

    vector<vector<int>> adjMat(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1;
        cin >> n2;
        adjMat[n1 - 1][n2 - 1] = 1;
        adjMat[n2 - 1][n1 - 1] = 1;
    }

    cout << "adj matrix : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }

    Solution solution;
    int ans = solution.findCircleNum(adjMat);

    cout << "No of provinces is " << ans;

    return 0;
}
