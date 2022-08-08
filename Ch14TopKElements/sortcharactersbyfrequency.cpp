#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : m) {
            pq.push({x.second, x.first});
        }
        string res;
        while (!pq.empty()) {
            pair<int, char> p = pq.top();
            for (int i = 0; i < p.first; i++) {
                res += p.second;
            }
            pq.pop();
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
    string s = "tree";
    sol.frequencySort(s);
    return 0;
}