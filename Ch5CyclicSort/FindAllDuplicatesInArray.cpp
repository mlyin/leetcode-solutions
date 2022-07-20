#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> list;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            list[nums[i]]++;
        }
        for (auto x : list) {
            if (x.second == 2) result.push_back(x.first);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v = {4,3,2,7,8,2,3,1};
    for (auto x : sol.findDisappearedNumbers(v)) {
        cout << x << " ";
    }
    cout << "\n";

}