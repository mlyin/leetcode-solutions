using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j;
        for (j = 0; j < nums.size(); j++) {
            if (nums[j] == 0) {
                k--;
            }
            if (k < 0 && nums[i++] == 0) {
                k++;
            }
        }
        return j-i;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};
    int res = sol.longestOnes(v, 2);
    cout << res << "\n";
}