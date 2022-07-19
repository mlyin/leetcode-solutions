#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if (target < letters[0] || target > letters[n-1]) {
        	return letters[0];
        }
        int lo = 0, hi = n-1;
        while (lo <= hi) {
        	int mi = lo + (hi-lo) / 2;
        	if (target < letters[mi]) {
        		hi = mi - 1;
        	} else {
        		lo = mi + 1;
        	}
        }
        return letters[lo % n];
    }
};

int main() {
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Solution sol;
	int x; cin >> x;
	vector<char> v = {'c', 'f', 'j'};
	cout << sol.nextGreatestLetter(v, 'c') << "\n";
	return 0;
}