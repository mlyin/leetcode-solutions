#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int res = 0;
    void solve(int index, int target, vector<int>& nums, int sum) {
        if (index >= nums.size() && sum == target) {
            res++;
            return;
        }
        if (index >= nums.size()) {
            return;
        }
        solve(index+1, target, nums, sum);
        solve(index+1, target, nums, sum - 2*nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tot = 0;
        for (auto x : nums) {
            tot += x;
        }
        solve(0, target, nums, tot);
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