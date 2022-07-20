using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1; int j = t.length() - 1;
        int skipsS = 0; int skipsT = 0;


        while (i >= 0 || j >= 0) {
            while (i >= 0){
                if (s[i] == '#') {
                    skipsS++;
                    i--;
                } else if (skipsS > 0) {
                    skipsS--;
                    i--;
                } else {
                    break;
                }
            }
            while (j >= 0){
                if (t[j] == '#') {
                    skipsT++;
                    j--;
                } else if (skipsT > 0) {
                    skipsT--;
                    j--;
                } else {
                    break;
                }
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    bool res = sol.backspaceCompare("ab##", "c#d#");
    if (res == true) {
        cout << "true";
    } else {
        cout << "false";
    }
}