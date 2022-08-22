#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-nums1[i] - nums2[j], {i, j}}); //{-2, 1, 1}
        set<pair<int, int>> s;
        while (!pq.empty()) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            if (s.count({pq.top().second.first, pq.top().second.second})) {
                pq.pop();
                continue;
            } else {
                res.push_back({nums1[pq.top().second.first], nums2[pq.top().second.second]});
                s.insert({pq.top().second.first, pq.top().second.second});
                pq.pop();
                if (i + 1 < nums1.size()) {
                    pq.push({-nums1[i+1] - nums2[j], {i+1, j}});
                }
                if (j + 1 < nums2.size()) {
                    pq.push({-nums1[i] - nums2[j+1], {i, j+1}});
                }
                if (res.size() == k) {
                    return res;
                }
            }
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