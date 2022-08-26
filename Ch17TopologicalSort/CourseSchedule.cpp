#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> sortedOrder;
        unordered_map<int, int> inDegree;
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            inDegree[i] = 0;
            graph[i] = vector<int>();
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            int parent = prerequisites[i][1], child = prerequisites[i][0];
            graph[parent].push_back(child);
            inDegree[child]++;
        }
        queue<int> sources;
        for (auto x : inDegree) {
            if (x.second == 0) {
                sources.push(x.first);
            }
        }
        while (!sources.empty()) {
            int vertex = sources.front();
            sources.pop();
            sortedOrder.push_back(vertex);
            vector<int> children = graph[vertex];
            for (auto child : children) {
                inDegree[child]--;
                if (inDegree[child] == 0) {
                    sources.push(child);
                }
            }
        }
        return (sortedOrder.size() == numCourses);
    }
};
int main() {
    #ifndef ONLINE_JUDGE
        clock_t tStart = clock();
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    Solution sol;
    vector<int> v = {1, 1, 1, 1, 1};
    cout << sol.findTargetSumWays(v, 3);
    return 0;
}