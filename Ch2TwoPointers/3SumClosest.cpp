using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (auto x : nums) {
          cout << x << " ";
        }
        cout << "\n";
        int closest = nums[0] + nums[1] + nums[2];
        int diff = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
          if (i != 0 && nums[i] == nums[i-1]) {
            continue;
          }
          int j = i + 1;
          int k = nums.size() - 1;
          while (j < k) {
            if (nums[i] + nums[j] + nums[k] == target) {
              j++;
              return target;
            }
            int currentSum = (nums[i] + nums[j] + nums[k]);
            if (abs(currentSum - target) < diff) {
              diff = abs(currentSum - target);
              closest = currentSum;
            }
            if (nums[i] + nums[j] + nums[k] < target && j < k) {
              j++;
            } else {
              k--;
            }
          }
        }
        return closest;
    }
};

int main() {
	Solution sol;
  vector<int> v = {-10,0,-2,3,-8,1,-10,8,-8,6,-7,0,-7,2,2,-5,-8,1,-4,6};
  int res = sol.threeSumClosest(v, 18);
  cout << res;
}
