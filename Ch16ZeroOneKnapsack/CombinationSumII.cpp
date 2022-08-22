#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    void solve(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &curr) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target) break;
            if (i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            curr.push_back(candidates[i]);
            solve(i+1, target -  candidates[i], candidates, ans, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(0, target, candidates, res, curr);
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