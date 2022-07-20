#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0);
        ListNode *prev = dummy;
        ListNode* curr;
        dummy->next = head;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        curr = pre->next;
        for (int i = 0; i < n - m; i++) {
            ListNode* temp = pre->next;
            pre->next = cur->next;
            cur->next ...
        }
    }
};

int main() {
    Solution sol;

}