using namespace std;

#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* slow = head;
        while (slow != NULL) {
            s.push(slow->val);
            slow = slow->next;
        }
        while (head != NULL) {
            int first = s.top();
            s.pop();
            if (head->val != first) {
                return false;
            }
            head = head-> next;
        }
        return true;
    }
};


int main() {
    Solution sol;
    if (sol.isHappy(19)) {
        cout << "true";
    } else {
        cout << "false";
    }
}