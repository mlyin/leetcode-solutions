#include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current_node = head;
        while (current_node != NULL) {
            ListNode* next_node = current_node->next;
            current_node->next = prev;
            prev = current_node;
            current_node = next_node;
        }
        return prev;
    }
    void merge (ListNode* first, ListNode* second) {
        while (first != null) {
            ListNode first_next = first->next;
            LsitNode second_next = second->next;
            first->next = second;
            if (first_next == NULL) {
                break;
            }
            second->next = first_next;
            first = first_next;
            second = second_next;

        }
    }
    void reorderList(ListNode* head) {
        if (head == null || head->next == null) return;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode l1 = head;
        ListNode l2 = reverse(slow);
        merge(l1, l2);
    }
};

int main() {
    Solution sol;

}