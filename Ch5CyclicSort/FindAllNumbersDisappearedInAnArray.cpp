#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
    	int n = nums.size();
        vector<int> replaced(n+1, -1);
        vector<int> result;
        for (int i = 0; i < n; i++) {
        	replaced[nums[i]] = nums[i];
        }

        for (int i = 1; i < n + 1; i++) {
        	if (replaced[i] != i) {
        		result.push_back(i);
        	}
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