#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<int, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        string res;
        pair<int, int> top1, top2;
        while (!pq.empty()) {
            top1 = pq.top();
            res += top1.second;
            pq.pop();
            if (!pq.empty()) {
                top2 = pq.top();
                pq.pop();
                res += top2.second;
                if (top2.first > 1) {
                    pq.push({top2.first - 1, top2.second});
                }
            }
            if (top1.first > 1) pq.push({top1.first - 1, top1.second});
        }
        for (int i = 1; i < res.size(); i++) {
            if (res[i] == res[i-1]) return "";
        }
        return res;
    }
};

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