using namespace std;

#include <bits/stdc++.h>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        if (intervals.size() == 0) {
          return result;
        }
        vector<int> current = intervals[0];
        for (auto x : intervals) {
          if (x[0] <= current[1]) {
            current[1] = max(x[1], current[1]);
          } else {
            result.push_back(current);
            current = x;
          }
        }
        result.push_back(current);
        return result;
    }
};

int main() {
  Solution sol;

}