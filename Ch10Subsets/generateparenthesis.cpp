#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    int openCount(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') cnt++;
        }
        return cnt;
    }
    int closeCount(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') cnt++;
        }
        return cnt;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<string> q;
        q.push("");
        while (!q.empty()) {
            string front = q.front();
            q.pop();
            if (openCount(front) == n && closeCount(front) == n) {
                res.push_back(front);
            } else {
                if (openCount(front) < n) {
                    q.push(front + '(');
                }
                if (openCount(front) > closeCount(front)) {
                    q.push(front + ')');
                }
            }
        }
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
        return res;
    }
};

int main() {
    Solution sol;
    sol.generateParenthesis(3);
}