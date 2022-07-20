#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int maxFirst = intervals[0][0];
        int n = intervals.size();
        vector<vector<int>> intervalsCopied(intervals);
        sort(intervals.begin(), intervals.end());
        vector<int> result(n, 0);
        map<int, int> m; 
        for (int i = 0; i < n; i++) {
            if (intervals[i][0] > maxFirst) {
                maxFirst = max(maxFirst, intervals[i][0]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (intervalsCopied[i] == intervals[j]) {
                    m.insert({i, j});
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            bool flag = false;
            if (intervalsCopied[i][1] > maxFirst) {
                result[i] = -1;
            } else {
                for (int j = 0; j < n; j++) {
                    if ((intervals[j][0] >= intervalsCopied[i][1]) && !flag) {
                        /*cout << "intervals[" << j << "]" << "[0]" << ">=" "intervalsCopied[" << i <<"][1]" << "\n";*/
                        for (auto x = m.begin(); x != m.end(); x++){
                            if (x->second == j) {
                                flag = true;
                                result[i] = x->first;
                                break;
                            }
                        }
                    }
                }   
            }
        }
        /*for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";*/
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{3, 4}, {2, 3}, {1, 2}};
    sol.findRightInterval(v);
}   