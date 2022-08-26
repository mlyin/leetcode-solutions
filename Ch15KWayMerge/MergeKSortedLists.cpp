#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

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
    struct valueCompare {
        bool operator() (const ListNode *x, const ListNode *y) {
            return x->val > y->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, valueCompare> pq;
        for (auto x : lists) {
            if (x != nullptr) {
                pq.push(x);
            }
        }
        ListNode* head = nullptr, *tail = nullptr;
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            if (head == nullptr) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = tail->next;
            }
            if (node->next != nullptr) {
                pq.push(node->next);
            }
        }
        return head;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<vector<int>> v = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    cout << sol.kthSmallest(v, 8);
    return 0;
}