#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (auto s : strs) {
            int numZeroes = 0;
            int numOnes = 0;
            for (auto c : s) {
                if (c == '0') numZeroes++;
                else numOnes++;
            }
            for (int i = m; i >= numZeroes; i--) {
                for (int j = n; j >= numOnes; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - numZeroes][j - numOnes] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {a
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