#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int numberOfOccurrences(vector<int> v, int x) {
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == x) cnt++;
        }
        return cnt;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> hash;
        vector<vector<int>> result;
        if (nums.empty()) {
            return result;
        }
        result.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int n = result.size();
            for (int j = 0; j < n; j++) {
                if ((numberOfOccurrences((result[j]), x)) >= hash[x]) {
                    vector<int> v = result[j];
                    v.push_back(x);
                    result.push_back(v);
                }
            }
            hash[x]++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> v1 = {1, 2, 2};
    sol.subsetsWithDup(v1);
}   