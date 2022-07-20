using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int index = 0;
        while (index <= end) {
            /*for (auto x : nums) {
                cout << x << " ";
            }
            cout << "\n";*/
            if (nums[index] == 0) {
                swap(nums[index], nums[start]);
                index++;
                start++;
            } else if (nums[index] == 1) {  
                index++;
            } else {
                swap(nums[index], nums[end]);
                end--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 2, 0};
    sol.sortColors(v);
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
}