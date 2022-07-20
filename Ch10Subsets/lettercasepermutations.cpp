#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        res.push_back(s);
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                int n = res.size();
                for (int j = 0; j < n; j++) {
                    vector<char> chs(res[j].begin(), res[j].end());
                    if (isupper(chs[i])) {
                        chs[i] = tolower(chs[i]);
                    } else {
                        chs[i] = toupper(chs[i]);
                    }
                    res.push_back(string(chs.begin(), chs.end()));
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "a1b2";
    sol.letterCasePermutation(s);
}   