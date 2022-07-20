#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[nums[i] - 1] < 0) {
                result.push_back(abs(nums[i]);
            }
            if (nums[nums[i] - 1] > 0) {
                nums[nums[i] - 1] *= -1;
            }
        }
        return result;
};

int main() {
    Solution sol;
    vector<int> v = {4,3,2,7,8,2,3,1};
    for (auto x : sol.findDisappearedNumbers(v)) {
        cout << x << " ";
    }
    cout << "\n";

}