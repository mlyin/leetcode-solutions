#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n <= 0) return res;
        if (n == 1) {
            res.push_back(0);
            return res;
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            adj[i] = vector<int>();
        }
        for (auto x : edges) {
            degree[x[0]]++;
            degree[x[1]]++;
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (n > 2) {
            int size = q.size();
            n -= size;
            while (size-- > 0) {
                int vertex = q.front();
                q.pop();
                for (auto i : adj[vertex]) {
                    degree[i]--;
                    if (degree[i] == 1) {
                        q.push(i);
                    }
                }
            }
        }
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> v = {1, 1, 1, 1, 1};
    cout << sol.findTargetSumWays(v, 3);
    return 0;
}