#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        for (auto x : map) {
            if (x.second == 1) {
                res.push_back(x.first);
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
    cout << sol.search(v, 166);
    return 0;
}