#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> left, end;
        for (auto x : nums) {
            left[x]++;
        }
        for (auto x : nums) {
            if (left[x] == 0) continue;
            left[x]--;  
            if (end[x-1] > 0) {
                end[x-1]--;
                end[x]++;
            } else if (left[i+1] > 0 && left[i+2] > 0) {
                left[i+1]--;
            }
        }
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> v = {1, 2, 3, 3, 4, 5};
    cout << sol.isPossible(v);
    return 0;
}