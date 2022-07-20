#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        result.push_back({nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            int n = result.size(); //equal to 1 on first iteration
            int numberToAdd = nums[i]; //2
            for (int j = 0; j < n; j++) { //{1} on the first iteration //go through all results, add two to first/end
                vector<int> currentVector = result[j]; // {1};
                for (int k = 0; k < currentVector.size() + 1; k++) {
                    vector<int> copyOfCurrentVector(currentVector);
                    copyOfCurrentVector.insert(copyOfCurrentVector.begin() + k, numberToAdd);
                    result.push_back(copyOfCurrentVector);
                }
            }
            for (int j = 0; j < n; j++) {
                result.erase(result.begin());
            }
        }
        /*for (auto x : result) {
            for (auto y : x) {
                cout << y << " ";
            }
            cout << "\n";
        }*/
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 2, 3};
    sol.permute(v1);
}   