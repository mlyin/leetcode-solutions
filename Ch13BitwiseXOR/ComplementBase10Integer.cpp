#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int bitwiseComplement(int n) {
       int x = 1;
       while (n > x) {
            x = 2*x + 1;
       }
       return x - n;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> v = {};
    cout << sol.bitwiseComplement(166);
    return 0;
}