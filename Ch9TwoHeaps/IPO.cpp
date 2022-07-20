#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class Solution {
    public:
    struct capitalCompare {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return x.first > y.first;
        }
    };

    struct profitCompare {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
            return y.first > x.first;
        }
    };

    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) { //w initial capital, k projects
        int n = profits.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, capitalCompare> minCapitalHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, profitCompare> maxProfitHeap;
        for (int i = 0; i < n; i++) {
            minCapitalHeap.push(make_pair(capital[i], i));
        }
        int availableCapital = w;
        //initial starting capital
        for (int i = 0; i < k; i++) {
            while (!minCapitalHeap.empty() && minCapitalHeap.top().first <= availableCapital) {
                auto capitalIndex = minCapitalHeap.top().second;
                minCapitalHeap.pop();
                maxProfitHeap.push(make_pair(profits[capitalIndex], capitalIndex));
            }
            if (maxProfitHeap.empty()) {
                break;
            }
            availableCapital += maxProfitHeap.top().first;
            maxProfitHeap.pop();
        }
        return availableCapital;
    }
};

int main() {
    Solution sol;
    vector<int> pfits = {1, 2, 3};
    vector<int> cpitl = {0, 1, 1};
    cout << sol.findMaximizedCapital(2, 0, pfits, cpitl);
}   