#include <bits/stdc++.h>

typedef long long ll;
ll a[1000001];
using namespace std;
const int MOD = (int) 1e9 + 7;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n <= 10) {
            vector<int>::iterator it;
            it = find(nums.begin(), nums.end(), target);
            if (it == nums.end()) {
                return -1;
            } else {
                return distance(nums.begin(), it);
            }
        }
        int rotationIndex = -1;
        int lo = 0;
        int hi = n-1;
        int currNum = -1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            // cout << "mi" << nums[mi] << "\n";
            if (mi + 1 < n) {
                if (nums[mi] > nums[mi+1]) {
                    rotationIndex = mi+1;
                    break;
                }
            }
            if (nums[mi] > currNum && nums[mi] > target) {
                currNum = nums[mi];
                hi = mi - 1;
            } else if (nums[mi] > currNum && nums[mi] < target) {
                currNum = nums[mi];
                lo = mi + 1;
            } else if (nums[mi] < currNum && nums[mi] > target) {
                currNum = nums[mi];
                hi = mi - 1;
            } else { //nums[mi] < currNum && nums[mi] < target
                currNum = nums[mi];
                lo = mi + 1;
            }
        }
        // cout << nums[rotationIndex] << "\n";
        if (rotationIndex == -1) {
            vector<int>::iterator it;
            it = find(nums.begin(), nums.end(), target);
            if (it == nums.end()) {
                return -1;
            }
            return distance(nums.begin(), it);
        } else if (target < nums[rotationIndex]) {//first half, need to add rotation index
            // cout << "1 reached" << "\n";
            vector<int>::const_iterator first = nums.begin();
            vector<int>::const_iterator last = nums.begin() + rotationIndex - 1;
            vector<int> newVec(first, last);
            vector<int>::iterator it;
            it = find(newVec.begin(), newVec.end(), target);
            if (it == newVec.end()) {
                return -1;
            }
            return (distance(newVec.begin(), it));
        } else { //second half
            // cout << "2 reached" << "\n";
            vector<int>::const_iterator first = nums.begin() + rotationIndex;
            vector<int>::const_iterator last = nums.end();
            vector<int> newVec(first, last);
            vector<int>::iterator it;
            it = find(newVec.begin(), newVec.end(), target);
            if (it == newVec.end()) {
                return -1;
            }
            return (distance(newVec.begin(), it) + rotationIndex);
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
    vector<int> v = {68,69,70,71,72,74,75,77,82,84,90,91,92,93,94,102,104,105,106,107,109,110,111,112,113,114,121,122,123,124,125,127,129,131,132,137,139,142,143,149,151,154,162,166,167,170,172,176,177,179,184,185,187,188,189,193,195,198,202,204,205,206,208,210,211,212,215,221,222,227,230,231,232,235,236,238,239,240,246,247,249,250,253,255,256,261,263,266,267,270,271,273,274,275,276,277,278,280,281,282,285,286,287,289,295,297,299,0,4,7,10,12,15,18,19,24,27,29,30,32,34,35,36,37,41,42,43,44,45,48,52,53,55,65,67};
    cout << sol.search(v, 166);
    return 0;
}