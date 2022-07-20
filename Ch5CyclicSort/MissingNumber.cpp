#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int n = nums.size();
        vector<int> replaced(n+1);

        for (int i = 0; i < n; i++) {
        	replaced[nums[i]] = nums[i];
        }

        for (int i = 0; i < n + 1; i++) {
        	if (replaced[i] != i) {
        		return i;
        	}
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> v = {0, 1};
    cout << sol.missingNumber(v);

}