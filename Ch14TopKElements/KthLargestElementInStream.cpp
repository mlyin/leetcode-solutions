#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class KthLargest {
public:
    int size;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    string s = "tree";
    sol.frequencySort(s);
    return 0;
}