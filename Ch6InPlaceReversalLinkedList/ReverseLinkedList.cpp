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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }
        ListNode* prev_node = head;
        ListNode* curr_node = head->next;
        head->next = NULL;
        while (curr_node->next != NULL) {
            ListNode* next_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node = curr_node; 
            curr_node = curr_node->next;
        }
        curr_node->next = prev_node;
        return curr_node;
    }
};