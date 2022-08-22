#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        int i = 0, j = 0;
        int cnt = 0;
        pq.push({-(matrix[i][j]), {i, j}});
        set<pair<int, int>> s;
        while (!pq.empty()) {
            i = pq.top().second.first;
            j = pq.top().second.second;
            if (s.count({i, j})) {
                pq.pop();
                continue;
            } else {
                cnt++;
                s.insert({i, j});
                pq.pop();
                if (i + 1 < matrix.size()) {
                    pq.push({-(matrix[i+1][j]), {i+1, j}});
                }
                if (j + 1 < matrix.size()) {
                    pq.push({-(matrix[i][j+1]), {i, j+1}});
                }
                cout << cnt << " " << matrix[i][j] << "\n";
                if (cnt == k) {
                    return matrix[i][j];
                }
            }
        }
        return -1;
    }
};
int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<vector<int>> v = {{0, 0, 0}, {2, 7, 9}, {7, 8, 11}};
    cout << sol.kthSmallest(v, 8);
    return 0;
}