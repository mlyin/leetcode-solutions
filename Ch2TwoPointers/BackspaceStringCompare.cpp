using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> sComplete;
        vector<char> tComplete;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                sComplete.push_back(s[i]);
            } else {
                if (sComplete.size() != 0) {
                    sComplete.pop_back();
                }
            }
        }
        for (int i = 0; i < t.length(); i++) {
            if (t[i] != '#') {
                tComplete.push_back(t[i]);
            } else {
                if (tComplete.size() != 0) {
                    tComplete.pop_back();
                }
            }
        }
        if (sComplete.size() != tComplete.size()) {
            return false;
        }
        for (int i = 0; i < sComplete.size(); i++) {
            if (sComplete[i] != tComplete[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    bool res = sol.backspaceCompare("a#c", "b");
    if (res == true) {
        cout << "true";
    } else {
        cout << "false";
    }
}