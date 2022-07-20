using namespace std;

#include <bits/stdc++.h>

class Solution {
 public:
    int maxSubArray(vector<int>& nums) {
      int maxSum = INT_MIN;
      int currentSum = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (currentSum <= 0) {
          currentSum = 0;
        }
        currentSum += nums[i];
        maxSum = max(currentSum, maxSum);
      }
      return maxSum;
    }
};


int main() {
	Solution sol;
	string str; cin >> str;
	cout << sol.lengthOfLongestSubstring(str) << "\n";
}