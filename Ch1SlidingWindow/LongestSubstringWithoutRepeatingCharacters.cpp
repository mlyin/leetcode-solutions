using namespace std;

#include <bits/stdc++.h>

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
  	map<char, int> seen;
    int longestSubstring = 0;
    int startingIndex = 0;
    for (int endingIndex = 0; endingIndex < s.length(); endingIndex++) {
    	if (seen.find(s[endingIndex]) != seen.end()) { //if it is found
    		startingIndex = max(startingIndex, seen[s[endingIndex]] + 1);
    	}
    	seen[s[endingIndex]] = endingIndex;
    	longestSubstring = max(endingIndex - startingIndex + 1, longestSubstring);
    }
    return longestSubstring;
  }
};


int main() {
	Solution sol;
	string str; cin >> str;
	cout << sol.lengthOfLongestSubstring(str) << "\n";
}