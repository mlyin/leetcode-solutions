#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> p;
        p = priority_queue<int>(nums.begin(), nums.end());
        while (k > 1) {
            p.pop();
            k--;
        }
        return p.top();
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