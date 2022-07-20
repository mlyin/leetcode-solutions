#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        if (expression.find('+') == string::npos && expression.find('-') == string::npos && expression.find('*') == string::npos) {
        	res.push_back(stoi(expression));
        } else {
        	for (int i = 0; i < expression.length(); i++) {
        		char c = expression[i];
        		if (!isdigit(c)) {
        			vector<int> leftP = diffWaysToCompute(expression.substr(0, i));
        			vector<int> rightP = diffWaysToCompute(expression.substr(i+1));
        			for (auto part1 : leftP) {
        			for (auto part2 : rightP) {
        				if (c == '+') {
        					res.push_back(part1+part2);
        				} else if (c == '*') {
        					res.push_back(part1*part2);
        				} else if (c == '-') {
        					res.push_back(part1-part2);
        				}
        			}
        		}
        		}
        	}
        }
        return res;
    }
};

int main() {
	#ifndef ONLINE_JUDGE
		clock_t tStart = clock();
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	Solution sol;
	return 0;
}
