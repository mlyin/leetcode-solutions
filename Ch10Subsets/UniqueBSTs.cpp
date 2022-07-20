#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	int dp[n+1];
    	dp[0] = 1, dp[1]=1;
    	for (int i = 2; i <= n; i++) {
    		dp[i] = 0;
    		for (int j = 0; j < i; j++) {
    			dp[i] += dp[j]*dp[i-j-1];
    		}
    	}
    	return dp[n];
    }
};

int main() {
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Solution sol;
	int x; cin >> x;
	cout << sol.numTrees(x);
	return 0;
}
