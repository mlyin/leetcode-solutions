using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
          for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
              v.push_back(i);
              v.push_back(j);
            }
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
