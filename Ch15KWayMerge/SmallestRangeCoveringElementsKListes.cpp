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
        bool operator() (const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
            return x.first > y.first;
        }
    };

    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare> pq;
        int start = 0;
        int end = INT_MAX;
        int currentMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (!nums[i].empty()) {
                pq.push({nums[i][0], {i, 0}});
            }
            currentMax = max(currentMax, nums[i][0]);
        }
        while (pq.size() == nums.size()) {
            auto node = pq.top();
            pq.pop();
            if (currentMax - node.first < end - start) {
                end = currentMax;
                start = node.first;
            }
            node.second.second++;
            if (nums[node.second.first].size() > node.second.second) {
                pq.push({nums[node.second.first][node.second.second], {node.second.first, node.second.second}});
                currentMax = max(currentMax, nums[node.second.first][node.second.second]);
            }
        }
        return {start, end};
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