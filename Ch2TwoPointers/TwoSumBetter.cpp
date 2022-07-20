using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int n = nums.size();
      int a[n];
      for (int i = 0; i < n; i++) {
        a[i] = nums[i];
      }
      sort(nums.begin(), nums.end());
      vector<int> v;
      int start = 0;
      int end = nums.size() - 1;
      while (start < end) {
        if (nums[start] + nums[end] == target) {
          break;
        } else if (nums[start] + nums[end] < target) {
          start++;
        } else {
          end--;
        }
      }
      for (int i = 0; i < n; i++) {
        if (a[i] == nums[start]) {
          v.push_back(i);
        } else if (a[i] == nums[end]) {
          v.push_back(i);
        }
      }
      return v;
    }
};


int main() {
	Solution sol;
  vector<int> v = {3,3,3,1,2,1,1,2,3,3,4};
  cout << sol.totalFruit(v);
}
