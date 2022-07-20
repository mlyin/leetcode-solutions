using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int currentSum = 0;
      int start = 0;
      int minSize = INT_MAX;
      for (int end = 0; end < nums.size(); end++) {
        currentSum += nums[end];
      
        while (currentSum >= target) {
          minSize = min(minSize, end - start + 1);
          currentSum -= nums[start];
          start++;
        }
      
      }
      if (minSize == INT_MAX) {
        return 0;
      } else {
        return minSize;
      }
    }
};


int main() {
	Solution sol;
  vector<int> v = {1, 4, 4};
	cout << sol.minSubArrayLen(4, v);
}