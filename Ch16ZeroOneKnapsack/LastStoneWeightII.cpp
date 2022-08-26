#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto x : stones) {
            sum += x;
        }
        bool dp[3000] = {false};
        dp[0] = true;
        for (auto x : stones) {
            for (int i = sum; i >= 0; i--) {
                if (i - x >= 0) {
                    if (dp[i-x]) dp[i] = true;
                }
            }
        }
        for (int i = sum /2; i >= 0; i--) {
            if (dp[i]) return (sum - i - i);
        }
        return 0;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<string> v = {"10","0001","111001","1","0"};
    cout << sol.findMaxForm(v, 5, 3);
    return 0;
}