using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    bool isHappy(int n) {
        vector<int> history;
        while (find(history.begin(), history.end(), n) == history.end()) {
            if (n == 1) {
                return true;
            } else {
                history.push_back(n); 
            }
            int temp = 0;
            while (n > 0) {
                temp += (n%10) * (n%10);
                n /= 10;
            }
            n = temp;
        }
        return false;
    }
};


int main() {
    Solution sol;
    if (sol.isHappy(19)) {
        cout << "true";
    } else {
        cout << "false";
    }
}