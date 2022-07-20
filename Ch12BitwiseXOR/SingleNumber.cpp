#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int lo = 0;
    	int hi = nums.size() - 1;
    	while (lo <= hi) {
    		int mi = lo + ((hi - lo) / 2);
    		if (nums[mi] == target) {
    			return mi;
    		} else if (nums[mi] > target) {
    			hi = mi - 1;
    		} else {
    			lo = mi + 1;
    		}
    	}
    	return -1;
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
	vector<int> v = {1, 4, 2, 1, 3, 2, 3};
	cout << sol.singleNumber(v) << "\n";
	return 0;
}
