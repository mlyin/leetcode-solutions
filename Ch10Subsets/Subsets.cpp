#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        result.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> v = result[j];
                v.push_back(x);
                result.push_back(v);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 2, 3};
    sol.subsets(v1);
}   