using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int total = 0;
        int currentProduct = 1;
        for (int start = 0, end = 0; end < nums.size(); end++) {
          currentProduct *= nums[end];
        while (start <= end && currentProduct >= k) {
           currentProduct /= nums[start++];
        }
        total += end - start + 1;
        }
        return total;
    }
};

int main() {
	Solution sol;
  vector<int> v = {10, 5, 2, 6};
  int res = sol.numSubarrayProductLessThanK(v, 100);
  cout << res << "\n";
}