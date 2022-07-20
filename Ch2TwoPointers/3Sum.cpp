using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> res;
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size(); i++) {
        if (i != 0 && nums[i] == nums[i-1]) {
          continue;
        }
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
          if (nums[i] + nums[j] + nums[k] == 0) {
            res.push_back({nums[i], nums[j], nums[k]});
            j++;
            while (j < k && nums[j] == nums[j-1]) {
              j++;
            }
          } else if (nums[i] + nums[j] + nums[k] < 0) {
            j++;
          } else {
            k--;
          }
        }
      }
      return res;
    }
};

int main() {
	Solution sol;
  vector<int> v = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> res = sol.threeSum(v);
  for (auto x : res) {
    cout << x[0] << " " << x[1] << " " << x[2];
    cout << "\n";
  }
}
