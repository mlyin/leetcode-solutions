#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            pq.push({(points[i][0] * points[i][0]) + (points[i][1] * points[i][1]), i});
        }
        for (int i = 0; i < k; i++) {
            vector<int> curr = points[pq.top().second];
            res.push_back(curr);
            pq.pop();
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
    vector<int> v = {};
    cout << sol.bitwiseComplement(166);
    return 0;
}