using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int start = 0;
      int end = 1;
      int n = nums.size();
      while (end < n) {
        if (nums[start] == nums[end]) {
          end++;
        } else {
          nums[start + 1] = nums[end];
          start++;
          end++;
        }
      }
      for (auto x : nums) {
        cout << x << " ";
      }
      cout << "\n";
      return start + 1;
    }
};


int main() {
	Solution sol;
  vector<int> v = {0,0,1,1,1,2,2,3,3,4};
  cout << sol.removeDuplicates(v);
}
