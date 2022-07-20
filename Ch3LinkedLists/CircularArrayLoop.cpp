#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        while (i < n) {
            int i = 0;
            int slow = i; int fast = i;
            
            slow = ((((slow + nums[slow]) % n) + n) % n);
            fast = ((((fast + nums[fast]) % n) + n) % n);
            fast = ((((fast + nums[fast]) % n) + n) % n);
        }
    }
};

int main() {
    Solution sol;

}