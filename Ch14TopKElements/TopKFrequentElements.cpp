#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        for (int i = 0; i < k; i++) {
            int mx = pq.top().second;
            res.push_back(mx);
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
    vector<int> v = {1, 1, 1, 2, 2, 3, 3};
    sol.topKFrequent(v, 2);
    return 0;
}