#include <bits/stdc++.h>
typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class FreqStack {
public:
    priority_queue<pair<int, pair<int,int>>> pq;
    map<int, int> m;
    int pos = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        pq.emplace(m[val]++, make_pair(pos++, val));
    }
    
    int pop() {
        auto top = pq.top();
        pq.pop();
        int x = top.second.second;
        m[x]--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    string s = "aab";
    sol.reorganizeString(s);
    return 0;
}