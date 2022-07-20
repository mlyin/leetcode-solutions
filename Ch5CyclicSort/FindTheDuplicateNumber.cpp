#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i]) - 1] < 0) {
                return abs(nums[i]);
            }
            nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
            for (int i = 0; i < nums.size(); i++) {
                    cout << nums[i] << " ";
                }
            cout << "\n";
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3,1,3,4,2};
    cout << sol.findDuplicate(v);
    cout << "\n";

}