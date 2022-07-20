using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0;
        int r = n - 1;
        for (int k = n - 1; k >= 0; k--) {
          if (abs(nums[l]) > abs(nums[r])) {
            res[k] = nums[l] * nums[l];
            l++;
          } else {
            res[k] = nums[r] * nums[r];
            r--;
          }
        }
        return res;
    }
};

int main() {
	Solution sol;
  vector<int> v = {-4, -1, 0, 3, 10};
  vector<int> res = sol.sortedSquares(v);
  for (auto x : res) {
    cout << x << " ";
    cout << "\n";
  }
}
