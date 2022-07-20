#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int IMAX = 100100;
int t, n;


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    	int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        while (lo <= hi) {
        	int mi = lo + (hi - lo) / 2;
        	if ((mi == 0 && arr[mi] > arr[mi+1]) || (mi == n - 1 && arr[mi] > arr[mi - 1])) {
        		return mi;
        	}
        	if (arr[mi] > arr[mi-1] && arr[mi] > arr[mi + 1]) {
        		return mi;
        	} else if (arr[mi] < arr[mi-1]) {
        		hi = mi - 1;
        	} else if (arr[mi] < arr[mi+1]) {
        		lo = mi + 1;
        	}
        }
        return -1;
    }
};

void solve() {
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Solution sol;

	vector<int>v = {3, 5, 3, 2, 0};
	cout << sol.peakIndexInMountainArray(v);
	return 0;
}