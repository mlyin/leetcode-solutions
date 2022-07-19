#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	if (nums.size() < 10) {
    		int loIndex = -1;
    		int hiIndex = -1;
    		bool foundLow = false;
    		for (int i = 0; i < nums.size(); i++) {
    			if (nums[i] == target && !foundLow) {
    				loIndex = i;
    				foundLow = true;
    			}
    			if (nums[i] == target) {
    				hiIndex = i;
    			}
    		}
    		return vector<int>{loIndex, hiIndex};
    	}
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        bool found = false;
        int midIndex = 0;
        int loIndex = 0;
        int hiIndex = 0;
        while (lo <= hi) {
        	int mi = lo + (hi - lo) / 2;
        	if (nums[mi] == target) {
        		midIndex = mi;
        		found = true;
        		break;
        	} else if (nums[mi] > target) {
        		hi = mi - 1;
        	} else {
        		lo = mi + 1;
        	}
        }
        if (found) { //finding lo
        	int lo = 0;
        	int hi = midIndex;
        	while (lo <= hi) {
        		int mi = lo + (hi - lo) / 2;
        		if (nums[mi] == target && mi > 0) {
        			if (nums[mi - 1] != target) {
        				loIndex = mi;
        				break;
        			} else {
        				hi = mi - 1;
        			}
        		}
        		if (nums[mi] == target && mi == 0) {
        			loIndex = mi;
        			break;
        		} else if (nums[mi] < target) {
        			hi = mi - 1;
        		} else {
        			lo = mi + 1;
        		}
        	}
        }
        if (found) {
        	int lo = midIndex;
        	int hi = n - 1;
        	while (lo <= hi) {
        		int mi = lo + (hi - lo) / 2;
        		if (nums[mi] == target && (mi + 1) < n) {
        			if (nums[mi+1] != target) {
        				hiIndex = mi;
        				break;
        			} else {
        				lo = mi + 1;
        			}
        		} 
        		if(nums[mi] == target && mi == n-1) {
        				cout << "reached";

        			hiIndex = mi;
        			break;
        		} else if (nums[mi] < target) {
        			lo = mi + 1;
        		} else {
        			hi = mi - 1;
        		}
        	}
        }
        if (found) {
        	return (vector<int>{loIndex, hiIndex});
        } else {
        	return (vector<int>{-1, -1});
        }
    }
};

int main() {
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Solution sol;
	vector<int> v = {0,0,1,1,1,2,2,3,3,3,4,4,4,4,5,5,6,6,6,8,10,10};
	for (auto x : sol.searchRange(v, 4)) {
		cout << x << " ";
	}
	return 0;
}