

#include <bits/stdc++.h>
using namespace std;



class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod = 100000;
        queue<pair<int , int>> q;
        vector<int> steptaken(100000 , 1e9);
        steptaken[start] = 0;
        q.push({start , 0});
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int steps = it.second;
            q.pop();
            if(node == end) return steps;
            for(auto it : arr){
                int current_node = (it * node) % 100000;
                int newstep = steps + 1;
                if(newstep < steptaken[current_node]){
                    steptaken[current_node] = newstep;
                    q.push({current_node , newstep});
                }
            }
        }
        return -1;
    }
};



int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int start, end;
    cin >> start >> end;
    Solution obj;
    cout << obj.minimumMultiplications(arr, start, end) << endl;
    
}
